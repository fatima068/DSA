/*Task 4 – Circular Queue
Implement a circular queue using arrays. Handle the following conditions correctly:
1. Enqueue when rear wraps around
2. Dequeue when front moves ahead
3. Prevent overflow when queue is full*/

#include <iostream>
using namespace std;
#include <string>

class CircularQueue {
    int* arr;
    int front;
    int back;
    int current;
    int size;
    
    public:
    CircularQueue(int size) : size(size), current(0), front(0), back(-1) {
        arr = new int[size];
    }
    
    ~CircularQueue() {
        delete[] arr;
    }
    
    void enqueue(int val) {
        if (full()) {
            cout << "queue is full" << endl;
            return;
        }
        
        back = (back + 1) % size;
        arr[back] = val;
        current++;
    }
    
    int dequeue() {
        if (empty()) {
            cout << "queue empty" << endl;
            return -1;
        }
        
        int toDequeue = arr[front];
        front = (front + 1) % size;
        current--;
        return toDequeue;
    }
    
    int getFront() {
        if (empty()) {
            cout << "queue empty" << endl;
            return -1;
        }
        return arr[front];
    }
    
    int getBack() {
        if (empty()) {
            cout << "queue empty" << endl;
            return -1;
        }
        return arr[back];
    }
    
    bool empty() {
        return current == 0;
    }

    bool full() {
        return current == size;
    }
    
    void print() {
        if (empty()) {
            cout << "queue empty" << endl;
            return;
        }
        
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        } while (i != (back + 1) % size);
        cout << endl;
    }
};

int main() {
    CircularQueue q(3);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print(); 
    cout << "Front: " << q.getFront() << endl;  
    cout << "Back: " << q.getBack() << endl;   \
    q.dequeue();
    q.print(); 
    q.enqueue(40);
    q.print();\
    q.dequeue();
    q.dequeue();
    q.print();  
    cout << "Front: " << q.getFront() << endl; 
    cout << "Back: " << q.getBack() << endl;   
}