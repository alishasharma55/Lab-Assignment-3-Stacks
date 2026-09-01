#include <iostream>
using namespace std;

#define MAX 5

int stack[MAX];
int top = -1;

// Push operation
void push() {
    int value;

    if (top == MAX - 1) {
        cout << "Stack Overflow! Stack is full.\n";
    }
    else {
        cout << "Enter value to push: ";
        cin >> value;

        top++;
        stack[top] = value;

        cout << value << " pushed into stack.\n";
    }
}

// Pop operation
void pop() {
    if (top == -1) {
        cout << "Stack Underflow! Stack is empty.\n";
    }
    else {
        cout << stack[top] << " popped from stack.\n";
        top--;
    }
}

// isEmpty operation
void isEmpty() {
    if (top == -1)
        cout << "Stack is Empty.\n";
    else
        cout << "Stack is not Empty.\n";
}

// isFull operation
void isFull() {
    if (top == MAX - 1)
        cout << "Stack is Full.\n";
    else
        cout << "Stack is not Full.\n";
}

// Display operation
void display() {
    if (top == -1) {
        cout << "Stack is Empty.\n";
    }
    else {
        cout << "Stack elements are:\n";

        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
}

// Peek operation
void peek() {
    if (top == -1) {
        cout << "Stack is Empty. No top element.\n";
    }
    else {
        cout << "Top element = " << stack[top] << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                isEmpty();
                break;

            case 4:
                isFull();
                break;

            case 5:
                display();
                break;

            case 6:
                peek();
                break;

            case 7:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
