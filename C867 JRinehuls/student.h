#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "degree.h"

using namespace std;

class Student {

public:
	Student(string, string, string, string, int, int[], DegreeProgram);

	void setStudentID(string studentID);
	string getStudentID();
	void setFirstName(string firstName);
	string getFirstName();
	void setLastName(string lastName);
	string getLastName();
	void setEmailAddress(string emailAddress);
	string getEmailAddress();
	void setAge(int age);
	int getAge();
	void setDaysInCourse(int daysInCourse[]);
	int* getDaysInCourse();
	void setDegreeProgram(DegreeProgram degreeProgram);
	DegreeProgram getDegreeProgram();
	void print();
	const static int NUM_COURSES = 3;

private:
	
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[NUM_COURSES];
	DegreeProgram degreeProgram;

};

#endif