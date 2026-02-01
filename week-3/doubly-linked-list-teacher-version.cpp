#include <iostream>
#include <cstdlib> // Required for malloc and free

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
void insert_beg(struct Node **start, int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = value; 
    newNode->prev = NULL;

    /* empty list */
    if (*start == NULL) {
        newNode->next = NULL;
        newNode->prev = NULL;
    }

    /* find last node */
    else
    {
        // store address of start in next of new node
        newNode->next = *start; // Link new node to the previous first node
        (*start)->prev = newNode; // Update previous first node's prev to new node
    }
    // update start to point to the new node. store address of new node in start
    *start = newNode;
}
void insert_end(struct Node **start, int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value; 
    newNode->next = NULL;

    /* empty list */
    if (*start == NULL) {
        newNode->prev = NULL;
        *start = newNode;
        return; // Exit the function after inserting the first node
    }

    /* find last node */
    struct Node *ptr = *start; // initialize temp pointer with address of first node
    while (ptr->next != NULL) // traverse till last node
        ptr = ptr->next; // move pointer to next node

    // change next of last node
    ptr->next = newNode;
    newNode->prev = ptr; // Update new node's prev to last node
}
void delete_beg(struct Node **start)
{
    if (*start == NULL) // empty list
        return;

    struct Node *ptr = *start;
    *start = (*start)->next; // update start to point to second node
    (*start)->prev = NULL; // Update new first node's prev to NULL
    free(ptr); // free memory of first node
}
void display_forward(struct Node *start)
{
    struct Node *ptr=start;
    std::cout << "Traversal in forward direction: \n";
    while (ptr != NULL) {
        std::cout << ptr->data << " --> ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}
int main() {
    struct Node* start = NULL; //linkedlist empty

    insert_end(&start, 10);
    insert_end(&start, 20);
    insert_beg(&start, 5);
    insert_end(&start, 30);
    delete_beg(&start);
    display_forward(start);
    return 0;
}