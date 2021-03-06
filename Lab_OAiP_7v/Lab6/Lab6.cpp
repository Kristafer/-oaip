// Lab6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <regex>
using namespace std;

int main()
{
	std::string text;
	cout<<"Input text"<<endl;
	getline(std::cin, text);
	cout << endl;
	regex rx(R"((?:^|\s)([+-]?[[:digit:]]+(?:[.,][[:digit:]]+)?)(?=$|\s))");
	smatch m;
	string str = text;
	while (regex_search(str, m, rx)) {
		cout << "Number found: " << m[1] << endl; 
		str = m.suffix().str(); 
	}
    return 0;
}

