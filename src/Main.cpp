#include <iostream>

extern "C" {
    namespace penguin {
        void testhelloworld() {
            std::cout << "Hello world! from Penguin engine" << std::endl;
        }
    }
}
