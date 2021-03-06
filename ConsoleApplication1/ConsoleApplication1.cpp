// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <windows.h>
#pragma comment(lib, "Winmm.lib")
#include <urlmon.h> 
#pragma comment(lib, "urlmon.lib")
#include <WinInet.h>
#pragma comment(lib, "WinInet.lib")
#include <ShlObj.h>
using namespace std;
int main()
{
	SetConsoleTitle(_T("SimpleUpdate v0.0.1"));
	cout << "SimpleUpdate v0.0.1" << endl;
	cout << "Checking app version...";
	string line = "";
	string line2 = "";
	ifstream myfile;
	myfile.open("version.txt");
	getline(myfile, line); // Saves the line in STRING.
	myfile.close();
	system("cls");
	cout << "Local Version number is " << line << ". Checking online version..." << endl;
	DeleteUrlCacheEntry(_T("http://nzgamer41.win/assets/version.txt"));
	URLDownloadToFile(NULL, _T("http://nzgamer41.win/assets/version.txt"), _T("test.txt"), 0, NULL);
	cout << "Done!" << endl;
	system("cls");
	cout << "Comparing versions...";
	ifstream online;
	online.open("test.txt");
	getline(online, line2); // Saves the line in STRING.
	online.close();
	cout << line << " " << line2 << endl;
	system("pause");
	if (line == line2)
	{
		system("cls");
		cout << "You have the latest version." << endl;
		system("pause");
		return 0;
	}
	else 
	{
	cout << "Downloading latest version...." << endl;
	SetConsoleTitle(_T("Downloading..."));
		DeleteUrlCacheEntry(_T("http://nzgamer41.win/assets/USSR.zip"));
		URLDownloadToFile(NULL, _T("http://nzgamer41.win/assets/USSR.zip"), _T("USSR.zip"), 0, NULL);
		system("del version.txt");
		DeleteUrlCacheEntry(_T("http://nzgamer41.win/assets/version.txt"));
		URLDownloadToFile(NULL, _T("http://nzgamer41.win/assets/version.txt"), _T("version.txt"), 0, NULL);
		cout << "Done!" << endl;
		system("del test.txt");
		system("PAUSE");
	}
}