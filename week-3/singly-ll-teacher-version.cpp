#include <iostream>
#include <cstdlib> // Required for malloc and free

struct Node {
    int data;
    struct Node *next;
};

void insert_beg(struct Node **start, int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
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
void insert_after(struct Node **start, int num, int value)
{
    struct Node *newNode, *ptr, *preptr;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    ptr = *start;
    preptr = ptr;
    // Traverse the list to find the node after which to insert
    while (preptr->data != num) { 
        preptr = ptr;
        ptr = ptr->next;   
    }
    preptr->next = newNode;
    newNode->next = ptr;
}
void insert_before(struct Node **start, int num, int value)
{
    struct Node *newNode, *ptr, *preptr;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    ptr = *start;
    // Traverse the list to find the node before next_node
    while (ptr->data != num) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = newNode;
    newNode->next = ptr;

}
void delete_after(struct Node **start, int num)
{
    struct Node *ptr, *preptr;
    ptr = *start;
    preptr = ptr;
    // Traverse the list to find the node to be deleted
    while (preptr->data != num) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
}
void delete_before(struct Node **start, int num)
{
   // implementation can be added here
}   
void display(struct Node *start)
{
    printf("Linked List elements:");
    struct Node *temp = start;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *start = NULL; //stores the address of first node

    insert_beg(&start, 10);
    insert_beg(&start, 20);
    insert_beg(&start, 30);
    display(start);
    insert_before(&start, 20, 25);
    display(start);
    insert_after(&start, 25, 27);
    display(start);
    delete_after(&start, 25);
    display(start);
    return 0;
}
