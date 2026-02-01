#include <iostream>
#include <cstdlib> // Required for malloc and free

struct Node {
    int data;
    struct Node *next;
};

void insert_beg(struct Node **start, int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    printf ("Address of newNode: %p\n", (void*)newNode);
    
    newNode->data = value; 

    /* empty list */
    if (*start == NULL) {
        newNode->next = NULL;
    }

    /* find last node */
    else
    {
        // store address of start in next of new node
        newNode->next = *start; // Link new node to the previous first node
        

    }
    // update start to point to the new node. store address of new node in start
    *start = newNode;
    // printf("Value of start in insert_beg inside function: %p\n", (void*)start);
}
void display(struct Node *start)
{
    printf("Linked List elements:");
    printf("Address of first Node: %p\n", (void*)start);
    struct Node *temp = start;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}
void insert_end(struct Node **start, int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value; 
    newNode->next = NULL;

    /* empty list */
    if (*start == NULL) {
        *start = newNode;
        return; // Exit the function after inserting the first node
    }

    /* find last node */
    struct Node *temp = *start; // initialize temp pointer with address of first node
    while (temp->next != NULL) // traverse till last node
        temp = temp->next; // move pointer to next node

    // change next of last node
    temp->next = newNode;
}
void delete_beg(struct Node **start)
{
    if (*start == NULL) // empty list
        return;

    struct Node *temp = *start; // store address of first node in temp
    *start = (*start)->next; // update start to point to second node
    free(temp); // free memory of first node
}
void delete_end(struct Node **start)
{
    if (*start == NULL) // empty list
        return;

    struct Node *temp = *start;

    // if only one node is present
    if (temp->next == NULL) {
        free(temp);
        *start = NULL;
        return;
    }

    // traverse to the second last node
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next); // free memory of last node
    temp->next = NULL; // update second last node's next to NULL
}
int main() {
    struct Node *start = NULL; //stores the address of first node

    insert_beg(&start, 10);

    printf("Value of start after insertion in main: %p\n", (void*)start);

    if (start == NULL)
        printf("Empty\n");
    else
        printf("Not Empty\n");
        printf("Value of start in main: %p\n", (void*)start);
        printf("Data at first node in main: %d\n", start->data);
    return 0;
}