// Lab3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
	double s, x, a, b, h;
	int k, i;
	cout << "Input a,b,h:" << endl;
	cin >> a >> b >> h;
	x = a;
	do {
		s = 0;
		for (i = 0; i <= 20; i++) {
			s += pow(cos(x), i) / (2 * i + 1);
		}
		cout << setw(15) << x << setw(15) << s << endl;
		x += h;
	} while (x <= b + h / 2);
	cout << endl;
    return 0;
}

