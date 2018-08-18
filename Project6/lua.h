#include <Windows.h>
#include <iostream>
#include <string>


int addy(int Offset) {
	return (Offset - 0x00400000 + (DWORD)GetModuleHandle("RobloxPlayerBeta.exe"));
}


typedef int(__cdecl *SINGLETON)(int a1, const char *a2);
SINGLETON SingletonPrint = (SINGLETON)addy(0x51EB70);


void cnsb() {
	DWORD CheckerValue;
	VirtualProtect((PVOID)&FreeConsole, 1, PAGE_EXECUTE_READWRITE, &CheckerValue);
	*(BYTE*)(&FreeConsole) = (0xC3);
}


void console(const char* csttl) {
	cnsb();
	AllocConsole();
	SetConsoleTitleA(csttl);
	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);
	HWND ConsoleHandle = GetConsoleWindow();
	::SetWindowPos(ConsoleHandle, HWND_TOPMOST, 0, 0, 0, 0, SWP_DRAWFRAME | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);
	::ShowWindow(ConsoleHandle, SW_NORMAL);
}
