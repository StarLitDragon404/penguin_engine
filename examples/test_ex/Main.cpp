// main.cpp

#include <dlfcn.h>
#include <iostream>

typedef void (*MyFunction)();

int main() {
    void *handle = dlopen("./libMain.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Error loading shared library: " << dlerror() << "\n";
        return 1;
    }

    MyFunction myFunction = (MyFunction)dlsym(handle, "testhelloworld");
    if (!myFunction) {
        std::cerr << "Error getting symbol: " << dlerror() << "\n";
        dlclose(handle);
        return 1;
    }

    myFunction();

    dlclose(handle);

    return 0;
}
