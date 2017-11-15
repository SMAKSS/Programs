// Sterling.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std; 

int fact(int);

 int main()
 {
	int sum=0,n,k;
	cout << "enter n:" << endl;
	cin >> n;
	cout << "enter k:" << endl;
	cin >> k;
	for (int i = 0; i <= k; i++)
		sum += (pow(-1, i)*fact(k)*pow(k - i, n)) / (fact(k - i)*fact(i));
	cout << "s(" << n << ";" << k << ")=" << sum / fact(k);
	_getch();
	return 0;
 }

 int fact(int x)
 {
	 if (x == 0 || x == 1)
		 return 1;
	 return x*fact(x - 1);
 }