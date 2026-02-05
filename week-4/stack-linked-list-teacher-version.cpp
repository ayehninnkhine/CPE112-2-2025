#include <iostream>
#include <cstdlib> // Required for malloc and free
struct Node {
    int data;
    struct Node *next;
};
void push(struct Node **top, int value)
{
    //time complexity: O(1)
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top; // Link new node to the previous top node
    *top = newNode; // Update top to point to the new node
}
int pop(struct Node **top)
{
    //time complexity: O(1)
    if (*top == NULL) {
        std::cout << "Stack Underflow\n";
        return -1; // Indicate stack is empty
    }
    struct Node *temp = *top; // Store address of top node
    int poppedValue = temp->data; // Get data from top node
    *top = (*top)->next; // Update top to point to the next node
    free(temp); // Free memory of the old top node
    return poppedValue; // Return the popped value
}
int peek(struct Node *top)
{
    //time complexity: O(1)
    if (top == NULL) {
        std::cout << "Stack is empty\n";
        return -1; // Indicate stack is empty
    }
    return top->data; // Return data of the top node
}
void display(struct Node *top)
{
    //time complexity: O(n)
    if (top == NULL) {
        std::cout << "Stack is empty\n";
        return;
    }
    std::cout << "Stack elements: ";
    struct Node *temp = top;
    while (temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
int main()
{
    struct Node *top = NULL; // Initialize stack as empty
    push(&top, 10);
    push(&top, 20); 
    push(&top, 30);
    std::cout << "Top element is: " << peek(top) << std::endl;
    std::cout << "Popped element is: " << pop(&top) << std::endl;
    std::cout << "Popped element is: " << pop(&top) << std::endl;
    std::cout << "Top element is: " << peek(top) << std::endl;
    display(top);
    return 0;
}
