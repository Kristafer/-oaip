// Lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	double x, y, s;
	cout << "Input x:" << endl;
	cin >> x;
	cout << "Input y: " << endl;
	cin>> y;
	double f_abs = fabs(x*y);
	if (f_abs > 10)	{
		s = exp((-1)*x);
		cout << "1 vetv. Result = " << s << endl;
	}
	else if (f_abs < 10) {
		s = pow(fabs(x + 4 * y),(double)1/3);
		cout << "2 vetv. Result = " << s << endl;
	}
	else{
		s = y*pow(x,2);
		cout << "3 vetv. Result = " << s << endl;
	}
    return 0;
}

