#include <iostream>
using namespace std;

// Node class for linked list
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Stack class using linked list
class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    // Push element onto stack
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    // Pop element from stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty, cannot pop" << endl;
            return;
        }
        Node* toDelete = top;
        top = top->next;
        delete toDelete;
    }

    // Get top element
    int peek() {
        if (isEmpty()) {
            return -1; // Return -1 for empty stack
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Get size of stack
    int size() {
        int count = 0;
        Node* temp = top;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Display stack elements (top to bottom)
    void print() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Queue class using two stacks
class Queue {
private:
    Stack stack1;  // Main stack for enqueue operations
    Stack stack2;  // Auxiliary stack for dequeue operations

public:
    void push(int val) {
        stack1.push(val);
        cout << "Enqueued: " << val << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty, cannot dequeue" << endl;
            return;
        }

        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.peek());
                stack1.pop();
            }
        }

        int dequeuedValue = stack2.peek();
        stack2.pop();
        cout << "Dequeued: " << dequeuedValue << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        if (stack2.isEmpty()) {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.peek());
                stack1.pop();
            }
        }

        return stack2.peek();
    }

    bool isEmpty() {
        return stack1.isEmpty() && stack2.isEmpty();
    }

    int size() {
        return stack1.size() + stack2.size();
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue (front to rear): ";

        if (!stack2.isEmpty()) {
            Stack tempStack;
            Stack stack2Copy = stack2;
            while (!stack2Copy.isEmpty()) {
                tempStack.push(stack2Copy.peek());
                stack2Copy.pop();
            }

            while (!tempStack.isEmpty()) {
                cout << tempStack.peek() << " ";
                tempStack.pop();
            }
        }

        if (!stack1.isEmpty()) {
            Stack tempStack;
            
            Stack stack1Copy = stack1;
            while (!stack1Copy.isEmpty()) {
                tempStack.push(stack1Copy.peek());
                stack1Copy.pop();
            }

            while (!tempStack.isEmpty()) {
                cout << tempStack.peek() << " ";
                tempStack.pop();
            }
        }

        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    cout << "========== QUEUE USING TWO STACKS ==========\n";

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Enqueue (Push)\n";
        cout << "2. Dequeue (Pop)\n";
        cout << "3. Peek (Front element)\n";
        cout << "4. Check if Empty\n";
        cout << "5. Get Size\n";
        cout << "6. Display Queue\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.push(value);
                break;

            case 2:
                q.pop();
                break;

            case 3:
                if (!q.isEmpty()) {
                    cout << "Front element: " << q.peek() << endl;
                } else {
                    cout << "Queue is empty!" << endl;
                }
                break;

            case 4:
                if (q.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;

            case 5:
                cout << "Queue size: " << q.size() << endl;
                break;

            case 6:
                q.print();
                break;

            case 7:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}