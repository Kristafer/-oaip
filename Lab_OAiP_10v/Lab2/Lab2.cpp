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
		s = log(fabs(x) + fabs(y));
		cout << "1 vetv. Result = " << s << endl;
	}
	else if (f_abs < 10) {
		s = exp(x+y);
		cout << "2 vetv. Result = " << s << endl;
	}
	else{
		s = pow(x,1/3)*sin(x);
		cout << "3 vetv. Result = " << s << endl;
	}
    return 0;
}

