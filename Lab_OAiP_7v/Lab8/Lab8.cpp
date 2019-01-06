// Lab8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
double calc(double x);
int main()
{
	double s, x, a, b, h;
	int k, i;
	cout << "Input a,b,h:" << endl;
	cin >> a >> b >> h;
	x = a;
	do {
		s = 0;
		cout << setw(15) << x << setw(15) << calc(x) << endl;
		x += h;
	} while (x <= b + h / 2);
	cout << endl;
	return 0;
}

double calc(double x) {
	double s = 0;
	int i;
	for (i = 0; i <= 20; i++) {
		s += pow(x, 2 * i) / cos(i*x);
	}
	return s;
 }

