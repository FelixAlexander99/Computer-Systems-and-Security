// Week12Pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int i = 10;
	int *ptr;
	ptr = &i;
	// the value of i
	cout << "i = " << i << "\n";     // "\n" is basically endl
	// the address of where i is kept
	cout << " &i = " << &i << "\n";
	// the value of ptr, which is the address of where i is kept
	cout << " ptr = " << ptr << "\n";
	// the value at the address that ptr points to 
	cout << "*ptr = " << *ptr << "\n";

	system("pause");

    return 0;
}

