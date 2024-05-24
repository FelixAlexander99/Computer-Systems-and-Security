// Passinganarraybyrefference.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//function getAverage
void getAverage(int *arr, int size, double *average)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	*average = sum / size;
}

int main()
{
	// an int array with 7 elements
	int balance[7] = { 100,220,31,91,550,0,10 };
	double avg;

	// pass pointer to the array as an argument and a refference to avg
	getAverage(balance, 7, &avg);

	// output the returned value
	cout << "Average value is: " << avg << endl;

	system("pause");

    return 0;
}

