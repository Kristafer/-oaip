// Lab6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	std::string text;
	cout<<"Input text"<<endl;
	getline(std::cin, text);
	cout << endl;
	int i, maxSize=0, position = 0, localPosition = 0, localSize=0,
		count = 0, localCount = 0;
	bool flagWord = false;
	for (i = 0; i < size(text); i++) {
		if (text[i] != ' ' && flagWord == false) {
			localSize = 1;
			localPosition = i + 1;
			flagWord = true; 
			localCount++;
		}
			if (text[i] != ' ' && flagWord == true) {
			localSize++;
		}
			if ((text[i] == ' ' && flagWord == true )|| (i+1 == size(text))) {
				if (maxSize < localSize) {
					maxSize = localSize;
					localSize = 0;
					position = localPosition;
					count = localCount;
				}
				flagWord = false;
			}
	}
	cout << "Number word: " << count << endl;
	cout << "Number position: " << position << endl;
    return 0;
}

