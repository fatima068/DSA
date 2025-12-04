#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;  
    Node* rear;  
    int count;   
    
public:
    Queue() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }
    
    ~Queue() {
        while (!isEmpty()) {
            pop();
        }
    }
    
    bool isEmpty() {
        return front == nullptr;
    }

    int size() {
        return count;
    }
    
    void push(int value) {
        Node* newNode = new Node(value);
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        
        count++;
    }
    
    void pop() {
        if (isEmpty()) {
            cout << "Queue is empty";
            return;
        }
        Node* temp = front;
        int poppedValue = front->data;
        front = front->next;
        
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        count--;
        
        cout << "Popped " << poppedValue << " from the queue.\n";
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue empty";
            return;
        }
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
        cout << "Queue size: " << count << endl;
    }
    
    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
};