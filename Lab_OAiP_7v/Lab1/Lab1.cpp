// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "math.h"
using namespace std;


int main()
{
	double x, y, z, a, b, c, h;
	cout << "Input x" << endl;
	cin >> x;
	cout << "Input y" << endl;
	cin >> y;
	cout << "Input z" << endl;
	cin >> z;
	a =5*atan(x) ;
	b = 0.25*acos(x) ;
	c = (x+3*fabs(x-y)+pow(x,2))/(fabs(x-y)*z+pow(x,2));
	h = a-(b*c);
	cout << "Result s =" << h << endl;
    return 0;
}

