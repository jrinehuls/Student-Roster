#include <string>
#include <iostream>
#include "roster.h"
using namespace std;


int main() {

	const string studentData[] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	  "A5,Justin,Rinehuls,jrinehu@wgu.edu,37,18,21,24,SOFTWARE" };

	cout << "C867 - Scripting and Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 006465984" << endl;
	cout << "Name: Justin Rinehuls\n" << endl;

	cout << "Displaying all students:" << endl;

	Roster classRoster = Roster();
	for (int i = 0; i < classRoster.NUM_OF_STUDENTS; i++) {
		classRoster.parse(studentData[i]);
	}
	classRoster.printAll();

	cout << "\nDisplaying invalid emails:" << endl;
	classRoster.printInvalidEmails();

	cout << "\nDisplaying average days in course: " << endl;
	for (int i = 0; i < classRoster.NUM_OF_STUDENTS; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}

	cout << "\nShowing students in degree program: SOFTWARE" << endl;
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	cout << "\nRemoving A3:" << endl;
	classRoster.remove("A3");
	classRoster.printAll();

	cout << "\nRemoving A3 again:" << endl;
	classRoster.remove("A3");

	cout << "\nDONE" << endl;

	classRoster.~Roster();

	return 0;
}