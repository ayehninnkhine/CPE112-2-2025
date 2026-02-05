#include   <iostream>

#define MAX 100 // Maximum size of stack
using namespace std;

struct Stack {
    int arr[MAX];
    int top;
};
void push(struct Stack *stack, int value)
{
    //time complexity: O(1)
    if (stack->top == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    stack->top = stack->top + 1;
    stack->arr[stack->top] = value;
    // Alternatively:
    // stack->arr[++stack->top] = value;
}
int pop(struct Stack *stack)
{
    //time complexity: O(1)
    if (stack->top == -1) {
        cout << "Stack Underflow\n";
        return -1; // Indicate stack is empty
    }
    return stack->arr[stack->top--];
}
int peek(struct Stack *stack)
{
    //time complexity: O(1)
    if (stack->top == -1) {
        cout << "Stack is empty\n";
        return -1; // Indicate stack is empty
    }
    return stack->arr[stack->top];
}
void display(struct Stack *stack)
{
    //time complexity: O(n)
    if (stack->top == -1) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = stack->top; i >= 0; i--)
        cout << stack->arr[i] << " ";
    cout << endl;
}
int main()
{
    struct Stack stack;
    stack.top = -1; // Initialize stack as empty

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    cout << "Top element is: " << peek(&stack) << endl;

    cout << "Popped element is: " << pop(&stack) << endl;
    cout << "Popped element is: " << pop(&stack) << endl;

    cout << "Top element is: " << peek(&stack) << endl;
    display(&stack);

    return 0;
}