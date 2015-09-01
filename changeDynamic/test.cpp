#include <iostream>

    extern "C" void func() {
        std::cout << "Called func in shared_object." << std::endl;
    }
