#include <iostream>
#include <cstdlib> // Required for malloc and free

struct Node {
    int data;
    struct Node* next;
};

int main() {
    // 1. Declare pointers for our nodes
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // 2. Allocate 3 nodes on the Heap using malloc
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // 3. Assign data and link them together
    
    // Node 1
    head->data = 10;    // Assign data
    head->next = second; // Link first node to the second

    // Node 2
    second->data = 20;
    second->next = third; // Link second node to the third

    // Node 3
    third->data = 30;
    third->next = NULL;   // The last node points to nothing (End of list)

    // 4. Print the list
    struct Node* temp = head;
    std::cout << "Linked List elements: ";
    while (temp != NULL) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;

    // 5. Free memory (In a real app, do this in a loop!)
    free(head);
    free(second);
    free(third);

    return 0;
}