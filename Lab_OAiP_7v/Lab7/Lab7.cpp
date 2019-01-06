// Lab7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

struct participant
{
	string nameCountry;
	string nameParticipant;
	string nameTeam;
	int playNumber;
	int age;
	double height;
	double weight;
};
int main()
{
	int countParticipants,i;
	cout << "Input count participants"<<endl;
	cin >> countParticipants;
	participant *participants = new participant[countParticipants];
	for (i = 0; i< countParticipants; i++) {
		cout << "Input Name Country" << endl;
		getline(cin >> ws, participants[i].nameCountry);
		cout << "Input nameParticipant" << endl;
		getline(cin >> ws, participants[i].nameParticipant);
		cout << "Input nameTeam" << endl;
		getline(cin >> ws, participants[i].nameTeam);
		cout << "Input playNumber" << endl;
		cin >> participants[i].playNumber;
		cout << "Input age" << endl;
		cin >> participants[i].age;
		cout << "Input height" << endl;
		cin >> participants[i].height;
		cout << "Input weight" << endl;
		cin >> participants[i].weight;
	}
	cout << endl << endl<<"Info participants(nameTeam >= 20 years)" << endl;
	for (i = 0; i, countParticipants; i++) {
		if (participants[i].age >= 20) {
			cout << "Name Country: " << participants[i].nameCountry << endl;
			cout << "nameParticipant: " << participants[i].nameParticipant << endl;
			cout << "nameTeam: " << participants[i].nameTeam << endl;
			cout << "playNumber: " << participants[i].playNumber << endl;
			cout << "age: " << participants[i].age << endl;
			cout << "height: " << participants[i].height << endl;
			cout << "weight: " << participants[i].weight << endl;
		}
	}
    return 0;
}

