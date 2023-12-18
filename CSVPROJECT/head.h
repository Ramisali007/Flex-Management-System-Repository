#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;
class MarkDetails {
public:
    string Course1; string marks1; string grade1;
    string Course2; string marks2; string grade2;
    string Course3; string marks3; string grade3;
};
class Attendance {
public:
    string status1; string date1; string time1;
    string status2; string date2; string time2;
    string status3; string date3; string time3;
};
class TimeTable {
public:
    string lecture1; string day1; string time1;
    string lecture2; string day2; string time2;
    string lecture3; string day3; string time3;
   
};
class Teacher
{
protected:
    string T_id;
    string T_password;
    string T_name;
    string T_Fname;
    string T_gender;
    string T_cnic;
    string T_contact;
    string T_address;
    string qualification;
    string salary;
    string T_department;
    TimeTable timetable;
public:
  

};
class Student
{
public:
    string S_id;
    string S_password;
    string S_name;
    string S_Fname;
    string S_gender;
    string S_cnic;
    string S_contact;
    string S_address;
    string feestatus;
    string S_department;
    MarkDetails mark;
    Attendance attendance;

};
class Admin :public Teacher, public Student
{
    string username;
    string password;
    int teacher_count;
    int student_count;
public:
    Admin();
    void AddTeacher();
    void AddStudent();
    void viewteachers();
    void viewstudents();
    void Edit_Student();
    void Edit_Teacher();
    void ViewTimeTable(string id);
    void AssignScore();
    void TakeAttendance();
    void ViewAttendance(string id);
    void ViewScore(string id);
    void ViewCourses(string id);
    void ViewFeeStatus(string id);
};
