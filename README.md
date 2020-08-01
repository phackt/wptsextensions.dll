- Load x64 visual studio environnement variables:  
```
C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat
```
  
- Go inside your source dir and run (BUILD MANUALLY to avoid unwanted dependencies):  
```
cl /LD /MT /EHa dllmain.cpp /Fe:WptsExtensions.dll
```
  
- Update bat script path:  
```
const TCHAR script[] = TEXT("C:\\Python27\\script.bat"):  
```
  
- Drop the DLL and script.bat in your writable directory (from the machine PATH)
  
- Reboot