#include <Windows.h>

LPWSTR GetLPWSTR(LPSTR in);

LPSTR GetLPSTR(LPWSTR in);

LPWSTR GetLPWSTR(DWORD in);

LPWSTR GetLPWSTR(const FILETIME ft);

LPWSTR ConnectTwoString(TCHAR *tString1, TCHAR *tString2);