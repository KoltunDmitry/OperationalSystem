#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <sstream>
//#include <conio.h>
#include <cstring>
using namespace std;
//Дескриптор ссылка на некий объект ОС
int main() {
	//double num1 = 8.20;
	//double num2 = 0;
	//cin >> num2;
	
	const char lpszAppName[] = "C:\\Users\\DIMA\\source\\repos\\LAB1\\Debug\\Creator.exe";
	STARTUPINFO si; 
	PROCESS_INFORMATION piApp; 
	ZeroMemory(&si, sizeof(STARTUPINFO));
	string standardPath = "C:\\Users\\DIMA\\source\\repos\\LAB1\\Debug\\";
	string temp = "";
	cout << "Input filename: ";
	getline(cin,temp);
	standardPath.append(temp);
	cout << "Inpur count of notes: " << endl;
	string count = "";
	getline(cin, count);
	string file1 = standardPath;
	standardPath.append(" ").append(count);
	char resChar[400];
	strcpy_s(resChar, standardPath.c_str());
	si.cb = sizeof(STARTUPINFO);
	if (!CreateProcess(lpszAppName, resChar, NULL, NULL, FALSE,
		CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp)) {
		system("pause");
		return 0;
	}
	cout << "The new process is created.\n";
	WaitForSingleObject(piApp.hProcess, INFINITE);//Ожидает, пока указанный объект не окажется в сигнальном состоянии или не истечет интервал тайм - аута.
	CloseHandle(piApp.hThread);
	CloseHandle(piApp.hProcess);
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	PROCESS_INFORMATION rep;
	cout << "Input fileName for output file:" << endl;
	string fileOutput = "C:\\Users\\DIMA\\source\\repos\\LAB1\\Debug\\";
	string name = "";
	getline(cin, name);
	cout << "Input average mark:" << endl;
	string mark = "";
	getline(cin, mark);
	file1.append(" ").append(fileOutput).append(name).append(" ").append(mark);
	char resultChar[400];
	strcpy_s(resultChar, file1.c_str());
	if (!CreateProcess("C:\\Users\\DIMA\\source\\repos\\LAB1\\Debug\\reporter.exe", resultChar, NULL, NULL, FALSE,
		CREATE_NEW_CONSOLE, NULL, NULL, &si, &rep)) {
		cout << "ERROR";
		system("pause");
		return 0;
	}
	system("pause");
	return 0;
}