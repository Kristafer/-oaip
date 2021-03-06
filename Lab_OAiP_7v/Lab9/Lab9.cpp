// Lab9.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;
FILE *file;

typedef struct {
	int workshopNumber;
	int detailCode;
	char name[100];
	int count;
} TDetail;
TDetail details[30];
char fileName[40];
int countWritedStruct = 0;

int Menu();
void SetNameFile();
void CreateNewFile();
void CreateListDetails();
void OpenFile();
void WriteResultConsole();
void WriteResultFile();
void SortArray();
void WriteResultALL();
void SearchDetail();
void BruteForce();
void BinarySearch();

int main()
{
	while (true)
	{
		switch (Menu())
		{
		case 1: SetNameFile(); break;
		case 2: CreateNewFile(); break;
		case 3: CreateListDetails(); break;
		case 4: OpenFile(); break;
		case 5: WriteResultConsole(); break;
		case 6: WriteResultFile(); break;
		case 7: WriteResultALL(); break;
		case 8: SortArray(); break;
		case 9: SearchDetail(); break;
		case 10: return 0;
		default: puts("Error. Input right number!");
		}
		puts("Press any key to continue");
		_getch();
		system("cls");
	}
}

int Menu()
{
	cout << "Input number:" << endl;
	cout << "1. Input file name" << endl;
	cout << "2. Create new file" << endl;
	cout << "3. Create list details" << endl;
	cout << "4. Open file" << endl;
	cout << "5. Show result(console) by workshopNumber" << endl;
	cout << "6. Show result(file) by workshopNumber" << endl;
	cout << "7. Show result(file) all" << endl;
	cout << "8. Sort array" << endl;
	cout << "9. Search item by code(after sort)" << endl;
	cout << "10. Exit" << endl;
	int i;
	cin >> i;
	return i;
}

void SetNameFile() {
	cout << "Input file name" << endl;
	cin >> fileName;
}

void CreateNewFile() {
	if ((file = fopen(fileName, "wb")) == NULL)
	{
		cout << "Error: Create File." << endl;
		exit(1);
	}
	cout << "OK" << endl;
	fclose(file);
}

void CreateListDetails()
{
	if ((file = fopen(fileName, "rb+")) == NULL)
	{
		cout << "Error: Create File." << endl;
		exit(1);
	}
	cout << "Input count details" << endl;
	cin >> countWritedStruct;
	for (int i = 0; i < countWritedStruct; i++)
	{
		cout << "Input workshop number " << endl;
		cin >> details[i].workshopNumber;
		cout << "Input detail code" << endl;
		cin >> details[i].detailCode;
		cout << "Input detail number " << endl;
		cin >> details[i].name;
		cout << "Input count details" << endl;
		cin >> details[i].count;
		fwrite(&details[i], sizeof(TDetail), 1, file);
	}
	fclose(file);
}

void OpenFile() // Открытие бинарного файла
{
	if ((file = fopen(fileName, "rb")) == NULL)
	{
		cout << "Error: Create File." << endl;
		exit(1);
	}
	countWritedStruct = 0;
	TDetail std;
	while (true)
	{
		int nwrt = fread(&std, sizeof(TDetail), 1, file);
		if (nwrt != 1) break;
		details[countWritedStruct] = std;
		cout << details[countWritedStruct].workshopNumber << " " << details[countWritedStruct].detailCode << " " << details[countWritedStruct].name << " "
			<< details[countWritedStruct].count << endl;
		countWritedStruct++;
	}
	fclose(file);
}

void WriteResultConsole()
{
	int workshopNumber;
	cout << "Input workshop Number" << endl;
	cin >> workshopNumber;
	for (int i = 0; i < countWritedStruct; i++)
		if (details[i].workshopNumber == workshopNumber)
			cout << details[i].workshopNumber << " " << details[i].detailCode << " " << details[i].name << " "
			<< details[i].count << endl;
}

void WriteResultFile()
{
	char namet[30];
	FILE *ft;
	cout << "Input file name" << endl;
	cin >> namet;
	if ((ft = fopen(namet, "w")) == NULL)
	{
		cout << "Error: Create File." << endl;
		exit(1);
	}
	char s[80];
	int workshopNumber;
	cout << "Input workshop number" << endl;
	cin >> workshopNumber;
	for (int i = 0; i < countWritedStruct; i++)
		if (details[i].workshopNumber == workshopNumber) {
			strcpy(s, to_string(details[i].workshopNumber).c_str());
			strcpy(s, details[i].name);
			strcpy(s, to_string(details[i].count).c_str());
			strcpy(s, to_string(details[i].detailCode).c_str());
			strcat(s, "\n");
			fputs(s, ft);
		}
	fclose(ft);
}

void SortArray() {
	int imin, i, j;
	TDetail t;
	for (i = 0; i < countWritedStruct - 1; i++)
	{
		imin = i;
		for (j = i + 1; j < countWritedStruct; j++) // Поиск минимального элемента
			if (details[imin].detailCode > details[j].detailCode)
				imin = j;
		if (imin != i) { // Перемещение минимального элемента
			t = details[imin];
			details[imin] = details[i];
			details[i] = t;
		}
	}
	WriteResultALL();
}

void WriteResultALL()
{
	for (int i = 0; i < countWritedStruct; i++)
		cout << details[i].workshopNumber << " " << details[i].detailCode << " " << details[i].name << " "
		<< details[i].count << endl;
}

void SearchDetail() {
	int  search;
	cout << "Input:" << endl
		<< "1. Brute force" << endl
		<< "2. Binary search" << endl;
	cin >> search;
	switch (search) {
	case 1:BruteForce();
		break;
	case 2:BinarySearch();
		break;
	}
}

void BruteForce() {
	int code;
	cout << "input code" << endl;
	cin >> code;
	int i;
	bool flag = false;
	for (i = 0; i < countWritedStruct; i++) {
		if (details[i].detailCode == code) {
			flag = true;
			break;
		}
	}
	if (flag) {
		cout << "Item Founded" << endl;
	}
	else
	{
		cout << "Item not Founded" << endl;
	}
}

void BinarySearch() {
	int code;
	cout << "input code" << endl;
	cin >> code;
	int i = 0, j = countWritedStruct , m;
	while (i < j)
	{
		m = (i + j) / 2; // Вычисление индекса среднего элемента
		if (code > details[m].detailCode) i = m + 1; // Исключение левой половины массива
		else j = m;
	}
	if (details[m].detailCode == code) {
		cout << "Item Founded" << endl;
	}
	else
	{
		cout << "Item not Founded" << endl;
	}
}