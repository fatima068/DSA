#include <iostream>
using namespace std;

// in a queue, u can only push at the back and pop from the front
// in a stack, u can pussh and pop only on the top of the stack
// to implement stack using queue ke functions: take 2 queues (1 is for storing data, other is helper)
// jab bhi kuch pop karna ho, queue ke front se pop hojayega aram se 
// but to push something, stack mei push bhi front pe hee hota but queue mei theres no push front function 
// so using only pop front and push back this is how u indirectly implement push front in queue to make it work like a stack
// example: Q1 = 1  2, Q2 (helper), now u have to push 3
// pop everything from q1 adn add to q2 Q1 = '', Q2 = 1  2
// add 3 to q1 : Q1 = 3, Q2 = 1  2
// now pop every element from q2 and push back to q1: Q1 = 3  1  2
// this way 3 has been pushed to the front without directly using a push front function 

class Node {
    public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class SimpleQueue { //linked list implementation
    private:
    Node* front;
    Node* rear;

    public:
    SimpleQueue() : front(nullptr), rear(nullptr) {}

    void push(int val) { // push to the back of queue
        Node* newNode = new Node(val);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    int pop() { // pop from the front of queue
        if (isEmpty()) {
            cout << "queue empty, cannot pop\n";
            return -1;
        }
        Node* toDelete = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        int retVal = toDelete->data;
        delete toDelete;
        return retVal;
    }

    bool isEmpty() {
        if (front == nullptr && rear == nullptr) {
            return true;
        }
        return false;
    }
    
    void print() {
        Node* temp = front;
        while(1) {
            cout << temp->data << " ";
            if (temp == rear) {
                cout << endl;
                return;
            }
            temp = temp->next;
        }
    }

    ~SimpleQueue() {
        while(!isEmpty()) {
            pop();
        }
    }
};

class StackUsingQueue {
    private:
    SimpleQueue queue;
    SimpleQueue queueTemp;

    public:
    void push(int val) {
        while (queue.isEmpty() == false) {
            queueTemp.push(queue.pop());
        }
        queue.push(val);
        while(queueTemp.isEmpty() == false) {
            queue.push(queueTemp.pop());
        }
    }

    int pop() {
        return queue.pop();
    }

    void print() {
        queue.print();
    }
};

int main() {
    StackUsingQueue s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();
    s.pop();
    s.pop();
    s.print();
    s.pop();
    s.pop();
}