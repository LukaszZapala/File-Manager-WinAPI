#include "WinMain.h"


// CHAR* convert to WCHAR*
LPWSTR GetLPWSTR(LPSTR in)
{
	const size_t cSize = strlen(in) + 1;
	wchar_t* out = new wchar_t[cSize];
	mbstowcs(out, in, cSize);

	return out;
}

// WCHAR* convert to CHAR*
LPSTR GetLPSTR(LPWSTR in)
{
	const size_t cSize = wcslen(in) + 1;
	char* out = new char[cSize];
	wcstombs(out, in, cSize);
	return out;
}

// DWORD convert to LPWCSTR
LPWSTR GetLPWSTR(DWORD in)
{
	wchar_t out[256] = { 0 };
	memset(out, '\0', 256);

	//swprintf_s(out, 10, L"%d", in);
	_ultow(in, out, 10);

	return out;
}

// FILETIME convert to LPWSTR;
LPWSTR GetLPWSTR(const FILETIME ft)
{
	SYSTEMTIME sTime;
	FileTimeToSystemTime(&ft, &sTime);				// Conversion from file time to system time

	TCHAR *year = new TCHAR[4];
	wcscpy(year, GetLPWSTR(sTime.wYear));
	TCHAR *month = new TCHAR[2];
	wcscpy(month, GetLPWSTR(sTime.wMonth));
	TCHAR *day = new TCHAR[2];
	wcscpy(day, GetLPWSTR(sTime.wDay));
	TCHAR *hour = new TCHAR[2];
	wcscpy(hour, GetLPWSTR(sTime.wHour));
	TCHAR *minute = new TCHAR[2];
	wcscpy(minute, GetLPWSTR(sTime.wMinute));

	int length = lstrlen(year) + lstrlen(month) + lstrlen(day) + lstrlen(hour)
		+ lstrlen(minute) + 2 * lstrlen(TEXT("-")) + lstrlen(TEXT(" ")) + lstrlen(TEXT(":"));

	TCHAR *out = new TCHAR[length];
	wcscpy(out, year);
	wcscat(out, TEXT("-"));
	wcscat(out, month);
	wcscat(out, TEXT("-"));
	wcscat(out, day);
	wcscat(out, TEXT(" "));
	wcscat(out, hour);
	wcscat(out, TEXT(":"));
	wcscat(out, minute);

	return out;
}

#define MAX_PATH_LENGHT 256

// Connect two TCHAR*
LPWSTR ConnectTwoString(TCHAR *tString1, TCHAR *tString2)
{
	TCHAR *tNewPath = new TCHAR[MAX_PATH_LENGHT];
	memset(tNewPath, '\0', MAX_PATH_LENGHT);

	if ((lstrlen(tString1) + lstrlen(tString2) <= MAX_PATH_LENGHT))
	{
		wcscpy(tNewPath, tString1);
		wcscat(tNewPath, tString2);
		//wcscat(tNewPath, TEXT("\\"));
		return tNewPath;
	}
	return NULL;
}