#include <iostream>
#include <cstdlib> // Required for malloc, calloc, and free

int main() {
    int n = 5;

    // 1. Using malloc
    // We request space for 'n' integers: n * sizeof(int)
    int* ptr_malloc = (int*)malloc(n * sizeof(int));

    // 2. Using calloc
    // We request 'n' elements, each the size of an integer
    int* ptr_calloc = (int*)calloc(n, sizeof(int));

    // Check if memory was successfully allocated
    if (ptr_malloc == NULL || ptr_calloc == NULL) {
        std::cout << "Memory Allocation Failed!" << std::endl;
        return 1;
    }

    std::cout << "Values in malloc array (usually garbage):" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << ptr_malloc[i] << " ";
    }

    std::cout << "\n\nValues in calloc array (always zero):" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << ptr_calloc[i] << " ";
    }

    // 3. Freeing the memory (Crucial Step!)
    free(ptr_malloc);
    free(ptr_calloc);

    std::cout << "\n\nMemory successfully freed." << std::endl;

    return 0;
}
