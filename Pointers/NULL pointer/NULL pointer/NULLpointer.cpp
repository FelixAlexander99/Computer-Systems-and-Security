// NULLpointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	int *ptr = NULL;
	cout << "The value of ptr is: " << ptr << endl;

	if (ptr) // succeeds if ptr is not NULL
		cout << "ptr is not NULL" << endl;

	if (!ptr) // succeeds if ptr is NULL
		cout << "ptr is NULL" << endl;

	system("pause");

    return 0;
}

