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
	a =pow(2,-x) ;
	b =sqrt(x+ pow(fabs(y),1/4)) ;
	c = pow(exp(x-1/sin(z)),1/3);
	h = a*b*c;
	cout << "Result h =" << h << endl;
    return 0;
}

