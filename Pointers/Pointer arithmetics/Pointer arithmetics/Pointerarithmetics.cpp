// Pointerarithmetics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	const int RANGE = 3;
	int arr[RANGE] = { 10,100,200 };
	int *ptr;

	//putting the array address in a pointer
	ptr = arr;

	for (int i = 0; i < RANGE; i++)
	{
		cout << "Address of arr[" << i << "] = " << ptr << endl;
		cout << "Value of arr[" << i << "] = " << *ptr << endl;

		//move the pointer to the next location
		ptr++;
	}
	system("pause");


    return 0;
}

