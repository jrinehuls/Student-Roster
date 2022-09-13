#include <string>
#include <iostream>
#include "student.h"

using namespace std;


Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse[0] = daysInCourse[0];
	this->daysInCourse[1] = daysInCourse[1];
	this->daysInCourse[2] = daysInCourse[2];
	this->degreeProgram = degreeProgram;
}

void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

string Student::getStudentID() {
	return studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

string Student::getFirstName() {
	return firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

string Student::getLastName() {
	return lastName;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

string Student::getEmailAddress() {
	return emailAddress;
}

void Student::setAge(int age) {
	this->age = age;
}

int Student::getAge() {
	return age;
}

void Student::setDaysInCourse(int daysInCourse []) {
	for (int i = 0; i < Student::NUM_COURSES; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}

int* Student::getDaysInCourse() {
	return daysInCourse;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}

void Student::print() {
	cout << this->getStudentID() << "\t";
	cout << this->getFirstName() << "\t";
	cout.width(10); cout << left << this->getLastName();
	cout.width(25); cout << left << this->getEmailAddress();
	cout << this->getAge() << "\t";
	for (int i = 0; i < NUM_COURSES; i++) {
		cout << this->getDaysInCourse()[i] << "\t";
	}
	cout << degreeProgramString[(int)this->getDegreeProgram()] << endl;
}