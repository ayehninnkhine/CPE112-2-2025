#include <iostream>

int main() {
   int a = 5, b = 10;
   int* p = &a;
   std::cout << "Initial values - a: " << a << ", b: " << b << std::endl;
   std::cout << "Memory addresses - a: " << &a << ", Memory address: " << &b << std::endl;
   std::cout << "Pointer p value: " << p << std::endl;
    *p = 20;
    std::cout << "After changing value via pointer p - a: " << a << ", b: " << b << std::endl;
    p = &b;
    std::cout << "Pointer p value: " << p << std::endl;
    *p = 30;
    std::cout << "After changing pointer p to point to b and modifying - " ;
    std::cout << "a: " << a << ", b: " << b << std::endl;

    return 0;
}