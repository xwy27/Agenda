// Copyright [2017] <Copyright XWY>
#include <functional>
#include <vector>
#include <list>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Storage.hpp"
#include "Path.hpp"

using std::list;
using std::shared_ptr;
using std::vector;
using std::string;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::stringstream;
using std::ios;

shared_ptr<Storage> Storage::m_instance = nullptr;

  Storage::Storage() {
    m_dirty = 0;
    readFromFile();
  }

  vector<string> toUser(const string& s) {
    vector<string> v;
    stringstream ss;
    ss << s;
    string temp;
    while (getline(ss, temp, ',')) {
      int start = temp.size();
      int length = temp.size();
      if (temp[0] == '\"') {
        length--;
        start = 1;
      }
      if (temp[temp.size()-1] == '\"') {
        length--;
      }
      if (start == 1) {
        temp = temp.substr(start, length);
        v.push_back(temp);
      }
    }
    return v;
  }

  Meeting toMeeting(const string& s) {
    vector<string> v;
    stringstream ss;
    ss << s;
    string temp;
    while (getline(ss, temp, ',')) {
      int start = temp.size();
      int length = temp.size();
      if (temp[0] == '\"') {
        length--;
        start = 1;
      }
      if (temp[temp.size()-1] == '\"') {
        length--;
      }
      if (start == 1) {
        temp = temp.substr(start, length);
        v.push_back(temp);
      }
    }
    if (v.size() != 5) {
      Meeting zero;
      return zero;
    }
    vector<string> memeber;
    stringstream name;
    name << v[1];
    string str;
    while (getline(name, str, '&')) {
      memeber.push_back(str);
    }
    Date start(v[2]);
    Date end(v[3]);
    Meeting meeting(v[0], memeber, start, end, v[4]);
    return meeting;
  }

  bool Storage::readFromFile(void) {
    ifstream userData(Path::userPath, ios::in);
    ifstream meetingData(Path::meetingPath, ios::in);
    if (!userData || !meetingData) {
      return 0;
    } else {
      string s;
      while (getline(userData, s)) {
        if (s.size() < 1) {
          continue;
        }
        vector<string> user = toUser(s);
        if (user.size() != 4) {
          continue;
        }
        m_userList.push_back(User(user[0], user[1], user[2], user[3]));
      }

      string str;
      while (getline(meetingData, str)) {
        if (str.size() < 1) {
          continue;
        }
        Meeting temp = toMeeting(str);
        if (temp.getTitle() != "") {
          m_meetingList.push_back(toMeeting(str));
        }
      }
    }
    userData.close();
    meetingData.close();
    return 1;
  }

  string toUserData(const User& s) {
    string out;
    out = out + "\"" + s.getName() + "\","
              + "\"" + s.getPassword() + "\","
              + "\"" + s.getEmail() + "\","
              + "\"" + s.getPhone() + "\"";
    return out;
  }

  string toMeetingData(const Meeting& m) {
    string out, memeber;
    Date empty;
    vector<string> v = m.getParticipator();
    for (auto i : v) {
      memeber = memeber + i + "&";
    }
    if (memeber[memeber.size()-1] == '&') {
      memeber = memeber.substr(0, memeber.size()-1);
    }
    out = out + "\"" + m.getSponsor() + "\","
              + "\"" + memeber + "\","
              + "\"" + empty.dateToString(m.getStartDate()) + "\","
              + "\"" + empty.dateToString(m.getEndDate()) +"\","
              + "\"" + m.getTitle() + "\"";
    return out;
  }

  bool Storage::writeToFile(void) {
    ofstream userData(Path::userPath, ios::out);
    ofstream meetingData(Path::meetingPath, ios::out);

    if (!userData || !meetingData) {
      return 0;
    } else {
      for (auto i : m_userList) {
        userData << toUserData(i) << endl;
      }
      for (auto i : m_meetingList) {
        meetingData << toMeetingData(i) << endl;
      }
    }
  }

  shared_ptr<Storage> Storage::getInstance(void) {
    if (!m_instance) {
      m_instance.reset(new Storage);
    }
    return m_instance;
  }

  Storage::~Storage() {
    if (m_dirty) {
      writeToFile();
    }
    m_instance.reset();
  }

  void Storage::createUser(const User &t_user) {
    m_dirty = 1;
    m_userList.push_back(t_user);
  }

  std::list<User> Storage::queryUser(std::function<bool(const User &)> filter) const {
    list<User> temp;
    for (auto &i : m_userList) {
      if (filter(i)) {
        temp.push_back(i);
      }
    }
    return temp;
  }

  int Storage::updateUser(std::function<bool(const User &)> filter,
                 std::function<void(User &)> switcher) {
    int count = 0;
    for (auto &i : m_userList) {
      if (filter(i)) {
        switcher(i);
        count++;
        m_dirty = 1;
      }
    }
    return count;
  }

  int Storage::deleteUser(std::function<bool(const User &)> filter) {
    int count = 0;
    auto itr = m_userList.begin();
    while (itr != m_userList.end()) {
      if (filter(*itr)) {
        count++;
        itr = m_userList.erase(itr);
        m_dirty = 1;
      } else {
        itr++;
      }
    }
    return count;
  }

  void Storage::createMeeting(const Meeting &t_meeting) {
    m_dirty = 1;
    m_meetingList.push_back(t_meeting);
  }

  std::list<Meeting> Storage::queryMeeting(
      std::function<bool(const Meeting &)> filter) const {
    list<Meeting> temp;
    for (auto &i : m_meetingList) {
      if (filter(i)) {
        temp.push_back(i);
      }
    }
    return temp;
  }

  int Storage::updateMeeting(std::function<bool(const Meeting &)> filter,
                    std::function<void(Meeting &)> switcher) {
    int count = 0;
    for (auto &i : m_meetingList) {
      if (filter(i)) {
        switcher(i);
        m_dirty = 1;
        count++;
      }
    }
    return count;
  }

  int Storage::deleteMeeting(std::function<bool(const Meeting &)> filter) {
    int count = 0;
    auto itr = m_meetingList.begin();
    while (itr != m_meetingList.end()) {
      if (filter(*itr)) {
        itr = m_meetingList.erase(itr);
        count++;
        m_dirty = 1;
      } else {
        itr++;
      }
    }
    return count;
  }

  bool Storage::sync(void) {
    if (m_dirty) {
      m_dirty = 0;
      return writeToFile();
    }
  }
