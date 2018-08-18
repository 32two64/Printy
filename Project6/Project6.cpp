#include <Windows.h>
#include <iostream>
#include <string>
#include "lua.h"



int main() { return 0; }


using namespace std;


namespace PrintExploit {
	namespace Integers {
		int printtype = 1; // 0 = Print, 1 = Info, 2 = Warn, 3 = Error
	}
}



void printy() {

	console("Printy"); // Title
	cout << "Printy Loaded! \n"; // Start Up Messages
	cout << "Welcome to Printy, Created by Klepto, with the help of Karky \n"; // Start Up Messages
	cout << "\n";
	cout << "Printy Ready ~ You May Now Print \n";
	cout << "\n";
	do {
		
		string outstr = "";
		getline(cin, outstr);
		SingletonPrint(PrintExploit::Integers::printtype, outstr.c_str());
		cout << "Printed Successfully! \n"; // Success Print Message
	} while (true);
}


int __stdcall DllMain(HMODULE DLL, DWORD Reason, void* Useless) {
	if (Reason == 1) {
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)printy, 0, 0, 0);
	}
	return TRUE;
}

