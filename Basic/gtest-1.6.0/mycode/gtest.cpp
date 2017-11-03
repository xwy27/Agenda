#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "Date.h"
#include "User.h"
#include "Meeting.h"
using std::string;
using std::cin;
using std::vector;
using std::to_string;
TEST (DateTest,TestSample) {
	Date blank;
	EXPECT_EQ(blank, Date::stringToDate("16-07-06/19:00"));
	Date date1(2016, 7, 6, 17, 19);
	EXPECT_EQ("2016-07-06/17:19", Date::dateToString(date1));
	EXPECT_TRUE(Date::isValid(Date("1800-02-29/00:01")));
}

TEST (UserTest, TestSample) {
	User us1("pear", "1234", "abc@qq.com", "123948394");
	EXPECT_EQ("pear",us1.getName());
}

TEST (MeetingTest, TestSample) {
	Meeting m1;
	m1.setSponsor("pear");
	EXPECT_EQ("pear", m1.getSponsor());
	std::vector<string> v;
	for (int i = 2; i >= 0; i--) {
		v.push_back(to_string(i));
	}
	m1.setParticipator(v);
	EXPECT_FALSE(m1.isParticipator("26"));
	EXPECT_TRUE(m1.isParticipator("2"));
}