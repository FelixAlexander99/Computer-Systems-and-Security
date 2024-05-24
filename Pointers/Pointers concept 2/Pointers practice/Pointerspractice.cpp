// Pointerspractice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int var = 20; // actual variable declaration
	int *ip; // pointer variable
	ip = &var; // store address of var in pointer variable

	cout << "Value of var variable: " << var << "\n";

	//print the address stored in ip pointer variable
	cout << "Address stored in ip variable: " << ip << "\n";

	//access the value at the address available in pointer
	cout << "Value of *ip variable: " << *ip << "\n";
	system("pause");

    return 0;
}

