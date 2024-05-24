// Terminatingaprocess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <TlHelp32.h>

using namespace std;

int main()
{
	HANDLE hProcessSnap;
	HANDLE hProcess;
	PROCESSENTRY32 pe32;
	bool processFound = 0;
	TCHAR virusName[] = TEXT("mspaint.exe");

	// Getting list of running processes
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
	{
		cout << "CreateToolhelp32Snapshot (of processes) is failed" << endl;
		return 0;
	}

	//Getting MS Paint Process ID

	//Set the size of the pe32 structure before using it
	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (!Process32First(hProcessSnap, &pe32))
	{
		cout << "Process32First is failed" << endl;
		//clean the snapshot object
		CloseHandle(hProcessSnap);
		return 0;
	}

	//Go through all the processes looking for mspaint.exe
	do
	{
		//print out the process name
		wcout << "Process name is:" << pe32.szExeFile << endl;

		//if the process name is mspaint.exe
		if (_tcscmp(pe32.szExeFile, virusName) == 0)
		{
			cout << "MsPaint process is found" << endl;
			processFound = 1;
			break;
		}
	} while (Process32Next(hProcessSnap, &pe32));

	//Terminating MSPaint process

	if (processFound)
	{
		//get a handle on the process with intention to terminate it
		hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pe32.th32ProcessID);
		if (TerminateProcess(hProcess, 1))
		{
			cout << "MSPaint is successfully terminated" << endl;
		}
		else 
		{
			cout << "MS Paint process is not found" << endl;
		}
	}

	system("pause");

    return 0;
}

