// Copyright [2017] <Copyright XWY>
#include <list>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include "Storage.hpp"
#include "AgendaService.hpp"
using std::list;
using std::vector;
using std::string;
using std::shared_ptr;

  AgendaService::AgendaService() {
    startAgenda();
  }

  AgendaService::~AgendaService() {
   quitAgenda();
  }

  bool AgendaService::userLogIn(const std::string &userName, const std::string &password) {
    list<User> temp = m_storage->queryUser([&](const User& a) {
        return (userName == a.getName() && password == a.getPassword());
      });
    if (temp.empty()) {
      return 0;
    } else {
      return 1;
    }
  }

  bool AgendaService::userRegister(const std::string &userName, const std::string &password,
                    const std::string &email, const std::string &phone) {
    list<User> temp = m_storage->queryUser([&](const User& a) {
        return (userName == a.getName());});
    if (temp.empty()) {
      m_storage->createUser(User(userName, password, email, phone));
      return 1;
    } else {
      return 0;
    }
  }

  bool AgendaService::deleteUser(const std::string &userName, const std::string &password) {
    int count = m_storage->deleteUser(
     [&](const User &u) {
      return (u.getName() == userName && u.getPassword() == password);
     });
    if (count) {
     deleteAllMeetings(userName);
     list<Meeting> toQuit = listAllParticipateMeetings(userName);
     for (auto i : toQuit) {
      quitMeeting(userName, i.getTitle());
     }
     return 1;
    }
    return 0;
  }

  std::list<User> AgendaService::listAllUsers(void) const {
    return m_storage->queryUser([] (const User& a) {return 1;});
  }

  bool titleValid(const string& title) {
    shared_ptr<Storage> temp = Storage::getInstance();
    list<Meeting> find = temp->queryMeeting([&](const Meeting& a) {
      return (a.getTitle() == title);
    });
    if (find.empty()) {
      return 1;
    } else {
      return 0;
    }
  }

  bool userValid(const string& userName) {
    shared_ptr<Storage> temp = Storage::getInstance();
    list<User> find = temp->queryUser([&](const User& a) {
      return (a.getName() == userName);
    });
    if (find.size() != 1) {
      return 0;
    } else {
      return 1;
    }
  }

  bool AgendaService::createMeeting(const std::string &userName, const std::string &title,
                     const std::string &startDate, const std::string &endDate,
                     const std::vector<std::string> &participator) {
    Date start(startDate);
    Date end(endDate);
    if (Date::isValid(start) && Date::isValid(end) &&
        titleValid(title) && userValid(userName)) {
     for (auto i : participator) {
      if (userValid(i)) {
       continue;
      } else {
       return 0;
      }
     }
     if (startDate == "0000-00-00/00:00" || endDate == "0000-00-00/00:00") {
      return 0;
     }
     if (start >= end) {
      return 0;
     }
     //user avaliable
     list<Meeting> find = listAllMeetings(userName);
     for (auto i : find) {
      if (!(start >= i.getEndDate() || end <= i.getStartDate())) {
       return 0;
      }
     }
     //participator avaliable
     if (!participator.size()) {
      return 0;
     } else {
      //user doesn't participate
      for (auto i : participator) {
       if (userName == i) {
        return 0;
       }
      }
      //unique participator
      auto p_temp = participator;
      std::sort(p_temp.begin(), p_temp.end());
      auto curt = p_temp.begin();
      auto prev = p_temp.begin();
      curt++;
      while (curt != p_temp.end()) {
       if (*prev == *curt) {
        return 0;
       } else {
        curt++;
        prev++;
       }
      }
      //participators are avaliable
      for (auto i : participator) {
       auto pMeeting = listAllMeetings(i);
       for (auto j : pMeeting) {
        if (!(j.getStartDate() >= end || j.getEndDate() <= start)) {
         return 0;
        }
       }
      }
      m_storage->createMeeting(Meeting(userName, participator, start, end, title));
      return 1;
     }
    }
    return 0;
  }

  bool AgendaService::addMeetingParticipator(const std::string &userName,
                              const std::string &title,
                              const std::string &participator) {
    //meeting exist
    auto meetingCheck = m_storage->queryMeeting(
     [&](const Meeting &a) {
      return (a.getSponsor() == userName && title == a.getTitle());
     });
    if (meetingCheck.size() != 1) {
     return 0;
    }
    //participator exist && participator != user
    if (!userValid(participator) || participator == userName) {
     return 0;
    }
    //participator avaliable
    auto pAvaliable = listAllMeetings(participator);
    for (auto i : pAvaliable) {
     if (!(meetingCheck.front().getStartDate() >= i.getEndDate() ||
      meetingCheck.front().getEndDate() <= i.getStartDate())) {
      return 0;
     }
    }
    //add participator
    int count = m_storage->updateMeeting(
     [&](const Meeting &a) {
      return (a.getTitle() == title &&
        a.getSponsor() == userName &&
        !a.isParticipator(participator));
     },
     [&](Meeting &a) {
      a.addParticipator(participator);
     });
    if (count) {
     return 1;
    }
    return 0;
  }

  bool AgendaService::removeMeetingParticipator(const std::string &userName,
                                 const std::string &title,
                                 const std::string &participator) {
    //meeting exist
    auto meetingCheck = m_storage->queryMeeting(
     [&](const Meeting &a) {
      return (a.getSponsor() == userName && title == a.getTitle());
     });
    if (meetingCheck.size() != 1) {
     return 0;
    } else {
     //check participator in the meeting
     if (!meetingCheck.front().isParticipator(participator)) {
      return 0;
     }
    }
    // //participator exist
    // if (!userValid(participator)) {
    //  return 0;
    // }
    //remove participator
    int count = m_storage->updateMeeting(
     [&](const Meeting &a) {
      return (a.getTitle() == title &&
        a.getSponsor() == userName);
     },
     [&](Meeting &a) {
      a.removeParticipator(participator);
     });
    if (count) {
     m_storage->deleteMeeting(
      [&](const Meeting &a) {
       return (a.getParticipator().size() == 0);
      });
     return 1;
    }
    return 0;
  }

  bool AgendaService::quitMeeting(const std::string &userName, const std::string &title) {
    int count = m_storage->updateMeeting(
      [&](const Meeting& a) {return (a.getTitle() == title && a.isParticipator(userName));},
      [&](Meeting& a) {
        a.removeParticipator(userName);
      });
    if (count) {
      m_storage->deleteMeeting([&](const Meeting& a) {
        return (a.getParticipator().size() == 0);
      });
      return 1;
    }
      return 0;
  }

  std::list<Meeting> AgendaService::meetingQuery(const std::string &userName,
                                  const std::string &title) const {
    list<Meeting> temp = m_storage->queryMeeting([&](const Meeting& a) {
      return ((a.getSponsor() == userName || a.isParticipator(userName)) && 
               a.getTitle() == title);
    });
    return temp;
  }

  std::list<Meeting> AgendaService::meetingQuery(const std::string &userName,
                                  const std::string &startDate,
                                  const std::string &endDate) const {
    Date start(startDate);
    Date end(endDate);
    list<Meeting> temp;
    if (!Date::isValid(start) || !Date::isValid(end) || startDate == "0000-00-00/00:00" || endDate == "0000-00-00/00:00") {
     return temp;
    }
    if (start > end) {
     return temp;
    }
    list<Meeting> all = listAllMeetings(userName);
    for (auto a : all) {
     if (!(start > a.getEndDate() || end < a.getStartDate())) {
      temp.push_back(a);
     }
    }
    return temp;
  }

  std::list<Meeting> AgendaService::listAllMeetings(const std::string &userName) const {
    list<Meeting> temp = m_storage->queryMeeting([&](const Meeting& a) {
      return (a.getSponsor() == userName || a.isParticipator(userName));
    });
    return temp;
  }

  std::list<Meeting> AgendaService::listAllSponsorMeetings(const std::string &userName) const {
    list<Meeting> temp = m_storage->queryMeeting([&](const Meeting& a) {
      return (a.getSponsor() == userName);
    });
    return temp;
  };

  std::list<Meeting> AgendaService::listAllParticipateMeetings(
      const std::string &userName) const {
    list<Meeting> temp = m_storage->queryMeeting([&](const Meeting& a) {
      return (a.isParticipator(userName));
    });
    return temp;
  }

  bool AgendaService::deleteMeeting(const std::string &userName, const std::string &title) {
    int count = m_storage->deleteMeeting([&](const Meeting& a) {
      return (a.getSponsor() == userName && a.getTitle() == title);
    });
    if (count) {
      return 1;
    } else {
      return 0;
    }
  }

  bool AgendaService::deleteAllMeetings(const std::string &userName) {
    int count = m_storage->deleteMeeting([&](const Meeting& a) {
      return (a.getSponsor() == userName);
    });
    if (count) {
      return 1;
    } else {
      return 0;
    }
  }

  void AgendaService::startAgenda(void) {
    m_storage = Storage::getInstance();
  }

  void AgendaService::quitAgenda(void) {
   //m_storage->sync();
    m_storage = nullptr;
  }
