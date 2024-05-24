// WindowsRegistryFunctionRegQueryInfoKey.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <tchar.h>

using namespace std;

int main()
{
	HKEY hk;
	DWORD ValuesNumber;     //Number of values for the key
	DWORD MaxValueNameLen;  //longest value name
	DWORD MaxValueDataLen;  //longest value data
	DWORD valueNameLen;
	DWORD dataLen;
	TCHAR NameToFind[] = TEXT("CO1508"); // name of the value in regedit

	TCHAR valueName[28], valuePath[MAX_PATH];

	//Opening the Run key
	RegOpenKey(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", &hk);

	//Get key values
	RegQueryInfoKey(hk, NULL, NULL, NULL, NULL, NULL, NULL, &ValuesNumber, &MaxValueNameLen, &MaxValueDataLen, NULL, NULL);

	cout << "Number of entities in Run is: " << ValuesNumber << "\n\n";

	//Listing key values
	if (ValuesNumber)
	{
		cout << "Now listing each value in it's path\n\n";
		for (int j = 0; j < (int)ValuesNumber; j++)
		{
			valueNameLen = MaxValueNameLen;
			dataLen = MaxValueDataLen;

			//Enumerate the key values
			RegEnumValue(hk, j, valueName, &valueNameLen, NULL, NULL, (LPBYTE)valuePath, &dataLen);

			//Use wcout instead of cout to print out TCHAR arrays
			wcout << "Name: " << valueName << "Path: " << valuePath << endl;
			
			//Deleting MSPaint
			wcout << valuePath << endl;
			// _tcscmp is used to compare 2 TCHAR values
			if (_tcscmp(valueName, NameToFind) == 0)
			{
				cout << "MSPaint entry is detected and will be deleted" << endl;
				RegDeleteValue(hk, valueName);
			}
			//...
		}
	}
	RegCloseKey(hk);

	system("pause");

    return 0;
}

