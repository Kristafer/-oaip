// Lab7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

struct Employee
{
	string fio;
	string position;
	int workExperience;//year
	int departmentNumber;
};
int main()
{
	int countEmployees,i;
	cout << "Input count employees"<<endl;
	cin >> countEmployees;
	Employee *employees = new Employee[countEmployees];
	for (i = 0; i< countEmployees; i++) {
		cout << "Input FIO" << endl;
		getline(cin >> ws, employees[i].fio);
		cout << "Input position" << endl;
		getline(cin >> ws, employees[i].position);
		cout << "Input workExperience(year)" << endl;
		cin >> employees[i].workExperience;
		cout << "Input departmentNumber" << endl;
		cin >> employees[i].departmentNumber;
	}
	cout << endl << endl<<"Info employees(workExperience >= 20 years)" << endl;
	for (i = 0; i, countEmployees; i++) {
		if (employees[i].workExperience >= 20) {
			cout << "FIO: " << employees[i].fio << endl;
			cout << "position: " << employees[i].position << endl;
			cout << "workExperience: " << employees[i].workExperience << endl;
			cout << "departmentNumber: " << employees[i].departmentNumber << endl;
		}
	}
    return 0;
}

