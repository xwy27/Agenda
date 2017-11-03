// Copyright [2017] <Copyright XWY>
#include "Date.h"
#include <initializer_list>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
using std::to_string;

  Date::Date() {
    m_year = m_month = m_day = m_hour = m_minute = 0;
  }

  Date::Date(int t_year, int t_month, int t_day, int t_hour, int t_minute) {
    m_year = t_year;
    m_month = t_month;
    m_day = t_day;
    m_hour = t_hour;
    m_minute = t_minute;
  }

  Date::Date(const std::string &dateString) {
    *this = stringToDate(dateString);
  }

  int Date::getYear(void) const {
    return m_year;
  }

  void Date::setYear(const int t_year) {
    m_year = t_year;
  }

  int Date::getMonth(void) const {
    return m_month;
  }

  void Date::setMonth(const int t_month) {
    m_month = t_month;
  }

  int Date::getDay(void) const {
    return m_day;
  }

  void Date::setDay(const int t_day) {
    m_day = t_day;
  }

  int Date::getHour(void) const {
    return m_hour;
  }

  void Date::setHour(const int t_hour) {
    m_hour = t_hour;
  }

  int Date::getMinute(void) const {
    return m_minute;
  }

  void Date::setMinute(const int t_minute) {
    m_minute = t_minute;
  }

  bool Date::isValid(const Date &t_date) {
    int year = t_date.getYear();
    if (year > 9999 || year < 1000 ||
        t_date.getMonth() < 1 || t_date.getMonth() > 12 ||
        t_date.getHour() < 0 || t_date.getHour() > 23 ||
        t_date.getMinute() < 0 || t_date.getMinute() > 59) {
      return false;
    } else {
      int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      if (year % 400 == 0 || (year % 4  == 0 && year % 100 != 0)) {
          day[2] = 29;
      }
      if (t_date.getDay() < 1 || t_date.getDay() > day[t_date.getMonth()]) {
        return false;
      } else {
        return true;
      }
    }
  }

  Date Date::stringToDate(const std::string &t_dateString) {
    Date zero;
    if (t_dateString.size() != 16) {
      return zero;
    }
    for (int i = 0; i < 16; ++i) {
      if (i == 4) {
        if (t_dateString[i] != '-') {
          return zero;
        }
      } else if (i == 7) {
        if (t_dateString[i] != '-') {
          return zero;
        }
      } else if (i == 10) {
        if (t_dateString[i] != '/') {
          return zero;
        }
      } else if (i == 13) {
        if (t_dateString[i] != ':') {
          return zero;
        }
      } else {
        if (t_dateString[i] < '0' || t_dateString[i] > '9') {
          return zero;
        }
      }
    }
    std::stringstream s;
    s << t_dateString;
    int year, month, day, hour, minute;
    char c;
    s >> year >> c >> month >> c >> day >> c >> hour >> c >> minute;
    Date temp(year, month, day, hour, minute);
    if (isValid(temp)) {
      return temp;
    } else {
      return zero;
    }
  }

  std::string Date::dateToString(const Date &t_date) {
    string out;
    if (isValid(t_date)) {
      out = out + std::to_string(t_date.getYear()) + "-";
      if (t_date.getMonth() / 10) {
        out = out + std::to_string(t_date.getMonth()) + "-";
      } else {
        out = out + "0" + std::to_string(t_date.getMonth()) + "-";
      }
      if (t_date.getDay() / 10) {
        out = out + std::to_string(t_date.getDay()) + "/";
      } else {
        out = out + "0" + std::to_string(t_date.getDay()) + "/";
      }
      if (t_date.getHour() / 10) {
        out = out + std::to_string(t_date.getHour()) + ":";
      } else {
        out = out + "0" + std::to_string(t_date.getHour()) + ":";
      }
      if (t_date.getMinute() / 10) {
        out = out + std::to_string(t_date.getMinute());
      } else {
        out = out + "0" + std::to_string(t_date.getMinute());
      }
    } else {
      out = "0000-00-00/00:00";
    }
    return out;
  }

  Date& Date::operator=(const Date &t_date) {
    setYear(t_date.getYear());
    setMonth(t_date.getMonth());
    setDay(t_date.getDay());
    setHour(t_date.getHour());
    setMinute(t_date.getMinute());
    return *this;
  }

  bool Date::operator==(const Date &t_date) const {
    bool flag = 0;
    if (getYear() == t_date.getYear() && getMonth() == t_date.getMonth() &&
       getDay() == t_date.getDay() && getHour() == t_date.getHour() &&
       getMinute() == t_date.getMinute()) {
      flag = 1;
    }
    return flag;
  }

  bool Date::operator>(const Date &t_date) const {
    bool flag = 0;
    if (getYear() > t_date.getYear()) {
      flag =1;
    } else {
      if (getMonth() > t_date.getMonth()) {
        flag = 1;
      } else {
        if (getDay() > t_date.getDay()) {
          flag =1;
        } else {
          if (getHour() > t_date.getHour()) {
            flag =1;
          } else {
            if (getMinute() > t_date.getMinute()) {
              flag = 1;
            }
          }
        }
      }
    }
    return flag;
  }

  bool Date::operator<(const Date &t_date) const {
    bool flag = 0;
    if (getYear() < t_date.getYear()) {
      flag =1;
    } else {
      if (getMonth() < t_date.getMonth()) {
        flag = 1;
      } else {
        if (getDay() < t_date.getDay()) {
          flag =1;
        } else {
          if (getHour() < t_date.getHour()) {
            flag =1;
          } else {
            if (getMinute() < t_date.getMinute()) {
              flag = 1;
            }
          }
        }
      }
    }
    return flag;
  }

  bool Date::operator>=(const Date &t_date) const {
    return (*this == t_date || *this > t_date);
  }

  bool Date::operator<=(const Date &t_date) const {
    return (*this == t_date || *this < t_date);
  }
