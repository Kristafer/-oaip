// Lab5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main()
{
	double **a, tmp;
	int i, j, n, imin, jmin, imax, jmax;
	cout << "Input size array: n" << endl;
	cin >> n;
	a = new double*[n];
	for (i = 0; i<n; i++)
		a[i] = new double[n];
	for (i = 0; i<n; i++) 
		for (j = 0; j<n; j++)
		{
			cout << "Input a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
	cout << "Array A:" << endl;
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
			cout << setw(9) << a[i][j] << " ";
		cout << endl;
	}
	imin = 0;
	jmin = 1;
	for (i = 0; i<n; i++)
		for (j = 0; j<i; j++)
		{
			if (a[i][j]<a[imin][jmin]) {
				imin = i;
				jmin = j;
			}
		}
	cout << "Index min elemet i = " << imin << " j = " << jmin<<endl;
	for (i = 0; i<n; i++)
		delete[] a[i];
	delete[]a;
	a = NULL;

    return 0;
}

