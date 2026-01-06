#include <iostream>

int main() {
    int myNumber = 42;
    int* myPointer = &myNumber; // Store the address of myNumber

    std::cout << "Value of myNumber: " << myNumber << std::endl;
    std::cout << "Address of myNumber (&myNumber): " << &myNumber << std::endl;
    std::cout << "Address stored in myPointer: " << myPointer << std::endl;

    return 0;
}