// Lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;
int main()
{
	int a[100],i, n;
	bool flag_sim=true;
	cout << "Input size array:" << endl;
	cin >> n;
	for (i = 0; i < n; i++) {
		cout << "Input a[" << i << "]=";
		cin >> a[i];
	}
	cout << "Array a:" << endl;
	for (i = 0; i < n; i++) {
		cout << a[i]<<" ";
	}
	cout << endl;
	for (i = 0; i < n; i++) {
		if (a[i] != a[n - 1 - i]) {
			flag_sim = false;
			break;
		}
	}

	if (flag_sim) {
		cout << "Array is symmetric" << endl;
	}
	else {
		cout << "Array isn't symmetric" << endl;
	}

}

