#include <iostream>
#include <sstream>
#include "module_a.h"

int main(int argc, char** argv) {

    int n = 0;

    if (argc != 2) {
        std::cout << "Invalid input parameters: only single integer is allowed" << std::endl;
        return 1;
    }

    std::istringstream ss(argv[1]);
    ss >> n;

    int count = module_a_func(n);
    std::cout << "Number of primes in [0," << n << "] is " << count << std::endl; 
    return 0;
}
