#include <iostream>
using namespace std;

// new data goes to rear
// data is popped from front
// has a fixed size, so mostly implemented using arrays 

class CircularQueue {
    private:
    int *arr;
    int capacity;
    int currentSize;
    int front;
    int rear;

    public:
    CircularQueue(int capacity) : capacity(capacity), front(0), rear(-1), currentSize(0) {
        arr = new int(capacity);
    } 

    void push(int val) {
        if (isFull()) {
            cout << "queue full, cannot push " << val << endl;
            return;
        }
        rear = (rear + 1) % capacity; // formula to calculate next array index for rear or front values in a circular queue
        arr[rear] = val;
        currentSize++;
    }

    void pop() {
        if(isEmpty()) {
            cout << "queue empty, cannot pop" << endl;
            return;
        }
        front = (front + 1) % capacity;
        currentSize--;
    }

    bool isEmpty() {
        if (currentSize == 0) return true;
        return false;
    }

    bool isFull() {
        if (currentSize == capacity) return true;
        return false;
    }

    void print() {
        if (isEmpty()) {
            cout << "queue empty, cannot print" << endl;
            return;
        }
        int temp = front;
        while(1) {
            cout << arr[temp] << "  ";
            if (temp == rear) {
                cout << endl;
                return;
            }
            temp++;
        }
    }

    ~CircularQueue() {
        while(!isEmpty()) {
            pop();
        }
        delete arr;
    }
};

int main() {
    CircularQueue q(3); 
    q.push(1);
    q.push(2);
    q.print();
    q.push(3);
    q.push(4);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
}