// main.cpp

#include <windows.h>
#include <iostream>

typedef void (*MyFunction)();

int main() {
    HMODULE handle = LoadLibrary("libMain.dll");
    if (!handle) {
        std::cerr << "Error loading shared library: " << GetLastError() << "\n";
        return 1;
    }

    MyFunction myFunction = (MyFunction)GetProcAddress(handle, "testhelloworld");
    if (!myFunction) {
        std::cerr << "Error getting symbol: " << GetLastError() << "\n";
        FreeLibrary(handle);
        return 1;
    }

    myFunction();

    FreeLibrary(handle);

    return 0;
}
