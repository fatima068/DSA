#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {} 
};

class Stack{
    private:
    Node* top;

    public:
    Stack() : top(nullptr) {}

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty, cannot pop" << endl;
            return;
        }
        Node* toDelete = top;
        top = top->next;
        delete toDelete;
        cout << "Popped value" << endl;
    }

    bool isEmpty() {
        if (top == nullptr) {
            return true;
        }
        return false;
    }

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
    }

};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);


    cout << "Stack contents: ";
    stack.print();
    cout << endl;

    stack.pop();
    stack.pop();
    cout << "After popping, stack contents: ";
    stack.print();
    stack.pop(); // Attempt to pop from empty stack
    cout << endl;
} 