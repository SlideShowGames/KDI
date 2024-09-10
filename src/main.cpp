// Hello World!

#include <cstdio>
#include <windows.h>
#include <iostream>

#import libs/KidiDiskAccessLib.dll
#import libs/smartWatch.dll // VTech wouldn't care if I supplied their DLLs right?

typedef int (__stdcall *f_kididiskinit)();

int main() //Stack overflow dll code https://stackoverflow.com/questions/8696653/dynamically-load-a-function-from-a-dll
{
    std::cout << "oooo   oooo ooooooooo  ooooo 
                888  o88    888    88o 888  
                888888      888    888 888  
                888  88o    888    888 888  
                o888o o888o o888ooo88  o888o "
                             
    std::cout << "Kidizoom Disk Initializer"  
  HINSTANCE hGetProcIDDLL = LoadLibrary("C:\\Documents and Settings\\User\\Desktop\\test.dll");

  if (!hGetProcIDDLL) {
    std::cout << "could not load the dynamic library" << std::endl;
    return EXIT_FAILURE;
  }

  // resolve function address here
  f_kididiskinit KidiDisk_Initialize = (f_kididiskinit)GetProcAddress(hGetProcIDDLL, "KidiDisk_Initialize");
  if (!KidiDisk_Initialize) {
    std::cout << "could not locate the function" << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "Dx3 Kididisk has been initalized" << KidiDisk_Initialize() << std::endl;

  return CALL_SUCCESS;
}


