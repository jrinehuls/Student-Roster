#include "roster.h"
#include <iostream>
#include <string>

Roster::Roster(){}
Roster::~Roster(){}


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	int daysInCourse[Student::NUM_COURSES] = {daysInCourse1, daysInCourse2, daysInCourse3};
	
	Student* student = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);
	classRosterArray[rosterArrayIndex] = student;
}

void Roster::remove(string studentID) {
	bool match = false;
	for (int i = 0, j = 0; i < NUM_OF_STUDENTS; i++) {
		if (studentID == classRosterArray[i]->getStudentID()) {
			match = true;
			continue;
		}
		classRosterArray[j] = classRosterArray[i];
		j++;
	}
	if (match) {
		NUM_OF_STUDENTS--;
	}
	if (!match) {
		cout << "The student with ID: " << studentID << " was not found." << endl;
	}
}

void Roster::printAll() {
	for (int i = 0; i < NUM_OF_STUDENTS; i++) {
		classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	int average {0};
	int total {0};
	Student* matchingStudent {nullptr};
	for (int i = 0; i < NUM_OF_STUDENTS; i++) {
		if (studentID == classRosterArray[i]->getStudentID()) {
			matchingStudent = classRosterArray[i];
		}
	}
	for (int j = 0; j < Student::NUM_COURSES; j++) {
		total += matchingStudent->getDaysInCourse()[j];
	}
	average = total / Student::NUM_COURSES;

	cout << "Student ID: " << studentID << " average days in course is: " << average << endl;
}

void Roster::printInvalidEmails() {
	string email;
	for (int i = 0; i < NUM_OF_STUDENTS; i++) {
		email = classRosterArray[i]->getEmailAddress();
		if (email.find(' ') != string::npos || email.find('.') == string::npos || email.find('@') == string::npos) {
			classRosterArray[i]->Student::print();
		}

	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < NUM_OF_STUDENTS; i++) {
		if (degreeProgram == classRosterArray[i]->getDegreeProgram()) {
			classRosterArray[i]->Student::print();
		}
	}
}

void Roster::parse(string studentData) {

	size_t right = studentData.find(",");
	string studentID = studentData.substr(0, right);

	size_t left = right + 1;
	right = studentData.find(",", left);
	string firstName = studentData.substr(left, right - left);

	left = right + 1;
	right = studentData.find(",", left);
	string lastName = studentData.substr(left, right - left);

	left = right + 1;
	right = studentData.find(",", left);
	string emailAddress = studentData.substr(left, right - left);

	left = right + 1;
	right = studentData.find(",", left);
	int age = stoi(studentData.substr(left, right - left));

	left = right + 1;
	right = studentData.find(",", left);
	int daysInCourse1 = stoi(studentData.substr(left, right - left));

	left = right + 1;
	right = studentData.find(",", left);
	int daysInCourse2 = stoi(studentData.substr(left, right - left));

	left = right + 1;
	right = studentData.find(",", left);
	int daysInCourse3 = stoi(studentData.substr(left, right - left));

	left = right + 1;
	size_t length = studentData.length();
	string degreeString = studentData.substr(left, length - left);

	int degreeIndex;
	for (int i = 0; i < sizeof(degreeProgramString); i++) {
		if (degreeString == degreeProgramString[i]) {
			degreeIndex = i;
		}
	}

	DegreeProgram degreeProgram = DegreeProgram(degreeIndex);


	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	rosterArrayIndex++;

}
