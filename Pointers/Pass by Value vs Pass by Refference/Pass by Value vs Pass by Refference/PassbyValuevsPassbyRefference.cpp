// PassbyValuevsPassbyRefference.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//A function to assign values to two integers
void func(int *x, int *y)
{
	*x = 200;
	*y = 40;
}

int main()
{
	int i = 10, j = 20;
	cout << "Values before calling func i: " << i << ", j: " << j << endl;

	// now passing two values i and j to the function
	func(&i, &j);

	cout << "Values after calling func i: " << i << ", j: " << j << endl;

	system("pause");

    return 0;
}

