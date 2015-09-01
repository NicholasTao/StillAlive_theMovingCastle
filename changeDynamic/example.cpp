#include <iostream>
    #include <dlfcn.h>

    typedef void (*func_t)();

    int main() {
        void * shared_object = dlopen("./test.so", RTLD_LAZY);
        func_t func = (func_t) dlsym(shared_object, "func");

        func();
        
        dlclose(shared_object);
    }
