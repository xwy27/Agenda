// Copyright [2017] <Copyright XWY>
#include <iostream>
#include <string>
#include <iomanip>
#include "AgendaService.hpp"
#include "AgendaUI.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::left;

  void showSymbol(const char& c, const int& times) {
  	for (int i = 0; i < times; ++i) {
  		cout << c;
  	}
  }

  void wrongInput() {
  	cout << "Wrong Input!" << endl
  		 << "Try Again!" << endl;
  }

  AgendaUI::AgendaUI() {
  	m_userName = m_userPassword = "";
  	startAgenda();
  }

  void AgendaUI::OperationLoop(void) {
  	bool loop = 1;
  	while (loop) {
  		showSymbol('-', 35);
  		cout << "Agenda";
  		showSymbol('-', 35);
  		cout << endl << "Action:" << endl;
  		cout << "l    - log in Agenda by user name and password" << endl 
  			 << "r    - register an Agenda account" << endl
  			 << "q    - quit Agenda" << endl;
  		showSymbol('-', 76);
  		string op = getOperation();
  		loop = executeOperation(op);
  		if (op == "l") {
  			userLogIn();
  		} else if (op == "r") {
  			userRegister();
  		} else if (op == "q") {
  			quitAgenda();
  			loop = 0;
  		} else {
  			wrongInput();
  		}
  	}
  }

  void AgendaUI::startAgenda(void) {
  	m_agendaService.startAgenda();
  }

  std::string AgendaUI::getOperation() {
  	cout << endl << "Agenda :~$ ";
  	string op;
  	cin >> op;
  	return op;
  }

  bool AgendaUI::executeOperation(const std::string &t_operation) {
  	if (t_operation == "l" || t_operation == "r") {
  		return 1;
  	} else if (t_operation == "q") {
  		return 0;
  	}
  	return 1;
  }

  void showOperation(const string m_userName) {
  	showSymbol('-', 35);
  	cout << "Agenda";
  	showSymbol('-', 35);
  	cout << endl
  		 << "Action :" << endl
  		 << "o    - log out Agenda" << endl
  		 << "dc   - delete Agenda account" << endl
  		 << "lu   - list all Agenda user" << endl
  		 << "cm   - create a meeting" << endl
  		 << "amp  - add meeting participator" << endl
  		 << "rmp  - remove meeting participator" << endl
  		 << "rqm  - request to quit meeting" << endl
  		 << "la   - list all meetings" << endl
  		 << "las  - list all sponsor meetings" << endl
  		 << "lap  - list all participator meetings" << endl
  		 << "qm   - query meeting by title" << endl
  		 << "qt   - query meeting by time interval" << endl
  		 << "dm   - delete meeting by title" << endl
  		 << "da   - delete all meetings" << endl;
  	showSymbol('-', 76);
  	cout << endl << "Agenda@" << m_userName << " :~# ";
  }

  void AgendaUI::userLogIn(void) {
  	cout << "[log in] [username] [password]" << endl << "[log in] ";
  	cin >> m_userName >> m_userPassword;
  	if (m_agendaService.userLogIn(m_userName, m_userPassword)) {
  		cout << "[log in] succeed!" << endl;
	  	string op;
	  	showOperation(m_userName);
	  	while (cin >> op) {
	  		if (op == "o") {
	  			break;
	  		} else if (op == "dc") {
	  			deleteUser();
	  			break;
	  		} else if (op == "lu") {
	  			listAllUsers();
	  		} else if (op == "cm") {
	  			createMeeting();
	  		} else if (op == "amp") {
	  			addMeetingParticipator();
	  		} else if (op == "rmp") {
	  			removeMeetingParticipator();
	  		} else if (op == "rqm") {
	  			quitMeeting();
	  		} else if (op == "la") {
	  			listAllMeetings();
	  		} else if (op == "las") {
	  			listAllSponsorMeetings();
	  		} else if (op == "lap") {
	  			listAllParticipateMeetings();
	  		} else if (op == "qm") {
	  			queryMeetingByTitle();
	  		} else if (op == "qt") {
	  			queryMeetingByTimeInterval();
	  		} else if (op == "dm") {
	  			deleteMeetingByTitle();
	  		} else if (op == "da") {
	  			deleteAllMeetings();
	  		} else {
	  			wrongInput();
	  		}
	  		showOperation(m_userName);
	  	}
  	} else {
  		cout << "[Error!] Wrong password or user doesn't exist!" << endl;
  	}
  }

  void AgendaUI::userRegister(void) {
  	cout << "[register] [username] [password] [email] [phone]" << endl
  		 << "[register] ";
  	string email, phone;
  	cin >> m_userName >> m_userPassword >> email >> phone;
  	if (m_agendaService.userRegister(m_userName, m_userPassword, email, phone)) {
  		cout << "[register] succeed!" << endl;
  	} else {
  		cout << "[Error!] The username has been registered!" << endl;
  	}
  }

  void AgendaUI::userLogOut(void) {
  	m_userPassword = m_userName = "";
  }

  void AgendaUI::quitAgenda(void) {
  	m_userName = m_userPassword = "";
  	m_agendaService.quitAgenda();
  }

  void AgendaUI::deleteUser(void) {
  	if (m_agendaService.deleteUser(m_userName, m_userPassword) ) {
  		cout << "[delete agenda account] succeed!" << endl;
  	} else {
  		cout << "[delete agenda account] fail!" << endl;
  	}
  }

  void AgendaUI::listAllUsers(void) {
  	cout << endl << "[list all users]" << endl;
  	showSymbol('-', 76);
  	cout << endl;
  	cout << left << std::setw(25) << "name" 
  		 << left << std::setw(25) << "email" 
  		 << left << std::setw(25) << "phone" << endl;
  	for (auto i : m_agendaService.listAllUsers()) {
  		cout << left << std::setw(25) << i.getName() 
  		 	 << left << std::setw(25) << i.getEmail()
  		 	 << left << std::setw(25) << i.getPhone() << endl;
  	}
  }

  void AgendaUI::createMeeting(void) {
  	cout << "[create meeting] [the number of participators]" << endl
  		 << "[create meeting] ";
  	bool flag = 1;
  	string number, name, title, stime, etime;
  	vector<string> p;
  	cin >> number;
  	for (int i = 0; i < number.size(); ++i) {
  		if (number[i] < '0' || number[i] > '9') {
  			flag = 0;
  			break;
  		}
  	}
  	if (flag) {
  		int num = std::stoi(number);
  		if (num != 0) {
		  	for (int i = 1; i <= num; ++i) {
		  		cout << "[create meeting] [please enter the participator "
		  			 << i << " ]" << endl;
		  		cout << "[create meeting] ";
		  		cin >> name;
		  		p.push_back(name);
		  	}
		  	cout << "[create meeting] Format for time: yyyy-mm-dd/hh:mm " << endl
		  		 << "[create meeting] [title] [start time] [end time]" << endl;
		  	cout << "[create meeting] ";
		  	cin >> title >> stime >> etime;
		  	if (m_agendaService.createMeeting(m_userName, title, stime, etime, p)) {
		  		cout << "[create meeting] succeed!" << endl;
		  	} else {
		  		cout << "[create meeting] Error! Failed!" << endl;
		  	}
  		} else {
  			cout << "[create meeting] Error! Failed!" << endl; 
  		}
  	} else {
  		cout << "[create meeting] Error! Failed!" << endl;
  	}
  }

  void AgendaUI::addMeetingParticipator(void) {
  	cout << endl;
  	cout << "[add participator] [meeting title] [participator username]" << endl
  		 << "[add participator] ";
  	string title, username;
  	cin >> title >> username;
  	if (m_agendaService.addMeetingParticipator(m_userName, title, username)) {
  		cout << "[add participator] succeed!" << endl;
  	} else {
  		cout << "[add participator] Error! Failed!" << endl;
  	}
  }

  void AgendaUI::removeMeetingParticipator(void) {
  	cout << endl;
  	cout << "[remove participator] [meeting title] [participator username]" << endl
  		 << "[remove participator] ";
  	string title, username;
  	cin >> title >> username;
  	if (m_agendaService.removeMeetingParticipator(m_userName, title, username)) {
  		cout << "[remove participator] succeed!" << endl;
  	} else {
  		cout << "[remove participator] Error! Failed!" << endl;
  	}
  }

  void AgendaUI::quitMeeting(void) {
  	cout << endl;
  	cout << "[quit meeting] [meeting title]" << endl
  		 << "[quit meeting] ";
  	string title;
  	cin >> title;
  	if (m_agendaService.quitMeeting(m_userName, title)) {
  		cout << "[quit meeting] succeed!" << endl;
  	} else {
  		cout << "[quit meeting] Error! Failed!" << endl;
  	}
  }

  void AgendaUI::listAllMeetings(void) {
  	cout << endl;
  	cout << "[list all meetings]" << endl << endl;
  	showSymbol('-', 100);
  	cout << endl;
  	list<Meeting> temp = m_agendaService.listAllMeetings(m_userName);
  	if (temp.size() != 0) {
		cout << left << std::setw(15) << "title"
	  		 << left << std::setw(15) << "sponsor"
	  		 << left << std::setw(20) << "start time"
	  		 << left << std::setw(20) << "end time"
	  		 << left << std::setw(20) << "participators"
	  		 << left << endl;
	  	for (auto i : temp) {
	  		cout << left << std::setw(15) << i.getTitle()
	  		 	 << left << std::setw(15) << i.getSponsor()
		  		 << left << std::setw(20) << i.getStartDate().dateToString(i.getStartDate())
		  		 << left << std::setw(20) << i.getEndDate().dateToString(i.getEndDate());
		  	vector<string> p = i.getParticipator();
		  	for (int i = 0; i < p.size(); ++i) {
		  		cout << p[i] << (i == p.size() - 1 ? "\n" : ",");
		  	}
	  	}
	} else {
		cout << "No Meeting is Matched!" << endl;
	}
  }

  void AgendaUI::listAllSponsorMeetings(void) {
  	cout << endl;
  	cout << "[list all sponsor meetings]" << endl << endl;
  	showSymbol('-', 100);
  	cout << endl;
  	list<Meeting> temp = m_agendaService.listAllSponsorMeetings(m_userName);
  	if (temp.size() != 0) {
	  	cout << left << std::setw(15) << "title"
	  		 << left << std::setw(15) << "sponsor"
	  		 << left << std::setw(20) << "start time"
	  		 << left << std::setw(20) << "end time"
	  		 << left << std::setw(20) << "participators"
	  		 << left << endl;
	  	for (auto i : temp) {
	  		cout << left << std::setw(15) << i.getTitle()
	  		 	 << left << std::setw(15) << i.getSponsor()
		  		 << left << std::setw(20) << i.getStartDate().dateToString(i.getStartDate())
		  		 << left << std::setw(20) << i.getEndDate().dateToString(i.getEndDate());
		  	vector<string> p = i.getParticipator();
		  	for (int i = 0; i < p.size(); ++i) {
		  		cout << p[i] << (i == p.size() - 1 ? "\n" : ",");
		  	}
	  	}
  	} else {
  		cout << "No Meeting is Matched!" << endl;
  	}
  }

  void AgendaUI::listAllParticipateMeetings(void) {
  	cout << endl;
  	cout << "[list all participator meetings]" << endl << endl;
  	showSymbol('-', 100);
  	cout << endl;
  	list<Meeting> temp = m_agendaService.listAllParticipateMeetings(m_userName);
  	if (temp.size() != 0) {
	  	cout << left << std::setw(15) << "title"
	  		 << left << std::setw(15) << "sponsor"
	  		 << left << std::setw(20) << "start time"
	  		 << left << std::setw(20) << "end time"
	  		 << left << std::setw(20) << "participators"
	  		 << left << endl;
	  	for (auto i : temp) {
	  		cout << left << std::setw(15) << i.getTitle()
	  		 	 << left << std::setw(15) << i.getSponsor()
		  		 << left << std::setw(20) << i.getStartDate().dateToString(i.getStartDate())
		  		 << left << std::setw(20) << i.getEndDate().dateToString(i.getEndDate());
		  	vector<string> p = i.getParticipator();
		  	for (int i = 0; i < p.size(); ++i) {
		  		cout << p[i] << (i == p.size() - 1 ? "\n" : ",");
		  	}
	  	}
  	} else {
  		cout << "No Meeting is Matched!" << endl;
  	}
  }

  void AgendaUI::queryMeetingByTitle(void) {
  	cout << endl;
  	cout << "[query meeting] [title]" << endl
  		 << "[query meeting] ";
  	string title;
  	cin >> title;
  	list<Meeting> temp = m_agendaService.meetingQuery(m_userName, title);
  	if (temp.empty()) {
  		cout << "[query meeting] No Meeting is Matched!" << endl;
  	} else {
  		cout << endl;
  		showSymbol('-', 100);
  		cout << endl;
  		cout << left << std::setw(15) << "title"
	  		 << left << std::setw(15) << "sponsor"
	  		 << left << std::setw(20) << "start time"
	  		 << left << std::setw(20) << "end time"
	  		 << left << std::setw(20) << "participators"
	  		 << endl;
	  	for (auto i : temp) {
	  		cout << left << std::setw(15) << i.getTitle()
	  		 	 << left << std::setw(15) << i.getSponsor()
		  		 << left << std::setw(20) << i.getStartDate().dateToString(i.getStartDate())
		  		 << left << std::setw(20) << i.getEndDate().dateToString(i.getEndDate());
		  	vector<string> p = i.getParticipator();
		  	for (int i = 0; i < p.size(); ++i) {
		  		cout << p[i] << (i == p.size() - 1 ? "\n" : ",");
		  	}
	  	}
  	}
  }

  void AgendaUI::queryMeetingByTimeInterval(void) {
  	cout << "Format of time : yyyy-mm-dd/hh:mm " << endl;
  	cout << "[query meetings] [start time] [end time]" << endl
  		 << "[query meetings] ";
  	string start, end;
  	cin >> start >> end;
  	if (start > end) {
  		cout << "[query meetings] Error!" << endl;
  	} else {
  		cout << endl;
  		showSymbol('-', 100);
  		cout << endl;
	  	cout << "[query meetings]" << endl << endl;
	  	cout << left << std::setw(15) << "title"
		  	 << left << std::setw(15) << "sponsor"
		  	 << left << std::setw(20) << "start time"
		  	 << left << std::setw(20) << "end time"
		  	 << left << std::setw(20) << "participators"
		  	 << endl;
		list<Meeting> temp = m_agendaService.meetingQuery(m_userName, start, end);
		if (temp.empty()) {
			cout << "[query meetings] Error!" << endl;
		} else {
			for (auto i : temp) {
				cout << left << std::setw(15) << i.getTitle()
		  		 	 << left << std::setw(15) << i.getSponsor()
			  		 << left << std::setw(20) << i.getStartDate().dateToString(i.getStartDate())
			  		 << left << std::setw(20) << i.getEndDate().dateToString(i.getEndDate());
			  	vector<string> p = i.getParticipator();
			  	for (int i = 0; i < p.size(); ++i) {
			  		cout << p[i] << (i == p.size() - 1 ? "\n" : ",");
			  	}
			}
		}  		
  	}
  }

  void AgendaUI::deleteMeetingByTitle(void) {
  	cout << "[delete meeting] [title]" << endl
  		 << "[delete meeting] ";
  	string title;
  	cin >> title;
  	if (m_agendaService.deleteMeeting(m_userName, title)) {
  		cout << "[delete meeting] succeed!" << endl;
  	} else {
  		cout << "[delete meeting] Error! Failed!" << endl;
  	}
  }

  void AgendaUI::deleteAllMeetings(void) {
  	if (m_agendaService.deleteAllMeetings(m_userName)) {
  		cout << "[delete all meeting] succeed!" << endl;
  	} else {
  		cout << "[delete all meeting] Error! Failed!" << endl;
  	}
  }

  void AgendaUI::printMeetings(const std::list<Meeting> &t_meetings) {

  }
