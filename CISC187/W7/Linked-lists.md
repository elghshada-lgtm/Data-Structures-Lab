Shada Elghariani

CISC 187

W7: Linked Lists

Here the the code: 
``` cpp
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Top of stack
Node* top = NULL;

// Check if stack is empty
bool isEmpty() {
    return (top == NULL);
}

// Push operation
void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop operation
void pop() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }

    Node* temp = top;
    cout << "Popped: " << temp->data << endl;
    top = top->next;
    delete temp; // prevent memory leak
}

// Peek operation
void peek() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Top element: " << top->data << endl;
}

// Display stack
void display() {
    Node* temp = top;

    cout << "Stack: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Driver program
int main() {
    cout << "Testing Stack:\n";

    push(10);
    push(20);
    push(30);

    display();

    peek();

    pop();
    display();

    pop();
    pop();

    // Test empty condition
    pop();
    peek();

    return 0;
}
```

## Reflection Questions


### 1. Why is a linked list efficient for stack implementation?
A linked list is efficient because elements can be added and removed from the head without shifting other elements. This makes operations way faster and flexible, especially when the stack size changes.


### 2. What is the time complexity of push and pop operations?
Both push and pop operations run in O(1) time because they only involve updating pointers at the top of the stack.


### 3. What happens if memory is not deallocated after pop?
If memory is not deallocated, it causes a memory leak. This means that unused memory is not returned to the system which can lead to performance issues or crashes over time.


### 4. Compare a stack implemented with an array versus a linked list.
An array based stack has a fixed size and might overflow while a linked list stack can grow. However, arrays are simpler and use less memory while linked lists require extra memory for pointers.
