#ifndef PATH_HPP
#define PATH_HPP

class Path {
 public:
  /**
   * user.csv path
   */
  static const char *userPath;

  /**
   * meeting.csv path
   */
  static const char *meetingPath;
};

//Reset the data pathes based on your own path 
const char *Path::meetingPath = "/home/administrator/Desktop/16340261/Agenda/data/meetings.csv";
const char *Path::userPath = "/home/administrator/Desktop/16340261/Agenda/data/users.csv";

#endif
