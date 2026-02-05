#include <iostream>
#include <cstdlib> // Required for malloc and free

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};
void insert_beg(struct Node **start, int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = value; 
    /* empty list */
    if (*start == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *start = newNode;
        return;
    }
    /* find last node */
    struct Node *ptr = *start;
    while (ptr->next != *start)
        ptr = ptr->next;
    newNode->prev = ptr;
    ptr->next = newNode;
    newNode->next = *start;
    (*start)->prev = newNode;
    *start = newNode; // update start to new node
}
void insert_end(struct Node **start, int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value; 

    /* empty list */
    if (*start == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *start = newNode;
        return;
    }

    /* find last node */
    struct Node *ptr = *start;
    while(ptr->next != *start)
        ptr = ptr->next;
    ptr->next = newNode;
    newNode->prev = ptr;
    newNode->next = *start;
    (*start)->prev = newNode;
}
void delete_beg(struct Node **start)
{
    if (*start == NULL) // empty list
        return;
    struct Node *temp = *start; // store address of first node in temp
    /* if only one node is present */
    if (temp->next == *start) {
        free(temp);
        *start = NULL;
        return;
    }   
    struct Node *last = (*start)->prev;
    *start = (*start)->next; // update start to point to second node
    last->next = *start;
    (*start)->prev = last;
    free(temp); // free memory of first node
}
void delete_end(struct Node **start)
{
    if (*start == NULL) // empty list
        return;
    struct Node *last = (*start)->prev;
    /* if only one node is present */
    if (last == *start) {
        free(last);
        *start = NULL;
        return;
    }
    struct Node *secondLast = last->prev;
    secondLast->next = *start;
    (*start)->prev = secondLast;
    free(last); // free memory of last node
}
void insert_after(struct Node **start, int num, int value)
{
    if (*start == NULL) // empty list
        return;

    struct Node *ptr = *start;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    while(ptr->data != num) {
        ptr = ptr->next;
    }
    newNode->prev = ptr;
    newNode->next = ptr->next;
    ptr->next->prev = newNode;
    ptr->next = newNode;
}

void insert_before(struct Node **start, int num, int value)
{
    if (*start == NULL) // empty list
        return;

    struct Node *ptr = *start;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    while(ptr->data != num) {
        ptr = ptr->next;
    }
    newNode->next = ptr;
    newNode->prev = ptr->prev;
    ptr->prev->next = newNode;
    ptr->prev = newNode;
}
void delete_after(struct Node **start, int num)
{
   /* Write your own code here */
   if (*start == NULL) // empty list
        return;

    struct Node *ptr = *start;
    while(ptr->data != num) {
        ptr = ptr->next;
    }
    struct Node *toDelete = ptr->next;
    ptr->next = toDelete->next;
    toDelete->next->prev = ptr;
    free(toDelete);
}
void delete_before(struct Node **start, int num)
{
    /* Write your own code here */
    if (*start == NULL) // empty list
        return;
    struct Node *ptr = *start;
    while(ptr->data != num) {
        ptr = ptr->next;
    }
    struct Node *toDelete = ptr->prev;
    toDelete->prev->next = ptr;
    ptr->prev = toDelete->prev;
    free(toDelete);    
}
void display(struct Node *start)
{
    if (start == NULL) { // empty list
        std::cout << "List is empty\n";
        return;
    }
    struct Node *temp = start;
    std::cout << "List elements: ";
    while (temp->next != start){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << temp->data << " "; // print last node
    std::cout << std::endl;
}
void display_equal_neighbors(struct Node *start)
{
    // Write your own code here
    if (start == NULL) { // empty list
        std::cout << "List is empty\n";
        return;
    }
    struct Node *temp = start;
    std::cout << "Nodes with equal neighbors: ";
    while(temp->next != start){
        if(temp->prev->data == temp->next->data){
            std::cout << temp->data << " ";
        }
        temp = temp->next;
    }
    // Check for the last node
    if(temp->prev->data == temp->next->data)
    {   std::cout << temp->data << " "; }
}
void display_difference_neighbors(struct Node *start, int k)
{
    // Write your own code here
    if (start == NULL) { // empty list
        std::cout << "List is empty\n";
        return;
    }
    struct Node *temp = start;
    std::cout << "Nodes with neighbors differing by " << k << ": ";
    while(temp->next != start){
        if(abs(temp->prev->data - temp->next->data) == k)
        {
            std::cout << temp->data << " ";
        }
        temp = temp->next;
    }
    // Check for the last node
    if(abs(temp->prev->data - temp->next->data) == k)
    {
        std::cout << temp->data << " ";
    }
    std::cout << std::endl;
}
int main() 
{
    struct Node *start = NULL; // Initialize empty list
    insert_beg(&start, 5);
    insert_beg(&start, 10);
    insert_end(&start, 15);
    display(start);
    insert_before(&start, 15, 12);
    display(start);
    insert_after(&start, 10, 8);
    display(start);
    display_equal_neighbors(start);
    return 0;
}