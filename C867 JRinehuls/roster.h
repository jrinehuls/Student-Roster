#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"
using namespace std;

class Roster {	

public:

	Roster();
	~Roster();

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void parse(string);
	void printByDegreeProgram(DegreeProgram degreeProgram);
	int NUM_OF_STUDENTS = 5;
	Student* classRosterArray[5] = {nullptr};

private:
	int rosterArrayIndex = 0;

};

#endif