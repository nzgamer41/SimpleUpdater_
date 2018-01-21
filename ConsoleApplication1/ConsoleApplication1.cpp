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
#include <algorithm>
using namespace std;
int main()
{
	string app = "";
	SetConsoleTitle(_T("SimpleUpdate v0.0.2"));
	cout << "SimpleUpdate v0.0.2" << endl;
	cout << "Identifying program...";
	ifstream app2;
	app2.open("app.txt");
	getline(app2, app); // Saves the line in STRING.
	app2.close();
	system("cls");
	cout << "Checking app version...";
	string line = "";
	string line2 = "";
	ifstream myfile;
	myfile.open("version.txt");
	getline(myfile, line); // Saves the line in STRING.
	myfile.close();
	system("cls");
	cout << "Local Version number is " << line << endl << "Checking online version..." << endl;
	/*wstring url = (L"http://nzgamer41.win/assets/" + app);
	wstring version = url + "/version.txt";
	LPCWSTR a;
	a = (LPCWSTR)version.c_str();
	DeleteUrlCacheEntry(a);
	URLDownloadToFile(NULL, a, _T("test.txt"), 0, NULL);
	*/
	// ^ needs re-writing but idk how to do it so I'm just gonna use system and wget.
	string url = "http://nzgamer41.win/assets/" + app;
	//system("del run.bat"); THIS IS JUST FOR DEBUGGING
	//system("del test.txt"); THIS IS JUST FOR DEBUGGING
	ofstream myfile3;
	myfile3.open("run.bat");
	myfile3 << "@echo off" << endl << "wget.exe --quiet -O test.txt " << url << "/version.txt"; // --quiet and @echo off
	myfile3.close();
	system("run.bat");
	cout << "Done!" << endl;
	system("cls");
	system("del run.bat");
	cout << "Comparing versions...";
	ifstream online;
	online.open("test.txt");
	getline(online, line2); // Saves the line in STRING.
	online.close();
	cout << line << " " << line2 << endl; // REMOVE THIS IS JUST FOR DEBUGGING
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
		/*DeleteUrlCacheEntry(_T("http://nzgamer41.win/assets/USSR.zip"));
		URLDownloadToFile(NULL, _T("http://nzgamer41.win/assets/USSR.zip"), _T("USSR.zip"), 0, NULL);
		system("del version.txt");
		DeleteUrlCacheEntry(_T("http://nzgamer41.win/assets/version.txt"));
		URLDownloadToFile(NULL, _T("http://nzgamer41.win/assets/version.txt"), _T("version.txt"), 0, NULL);
		*/
		myfile3.open("download.bat");
		myfile3 << "@echo off" << endl << "del " << app << ".exe" << endl  << "del version.txt" << endl << "wget.exe --quiet -O " << app << ".exe " << url << "/" << app << ".exe" << endl << "wget.exe --quiet -O version.txt " << url << "/version.txt" << endl; // --quiet and @echo off
		myfile3.close();
		system("download.bat");
		cout << "Done!" << endl;
		system("del download.bat");
		system("del test.txt");
		system("PAUSE");
	}
}