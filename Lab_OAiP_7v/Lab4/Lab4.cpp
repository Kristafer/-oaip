// Lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;
int main()
{
	int a[100],b[100],i, n,m;
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
	cout << "Input M for move elements" << endl;
	cin >> m;
	for (i = 0; i < n; i++) {
		b[i] = a[(i + m) % n];
	}
	cout << "Array b(move):" << endl;
	for (i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}

