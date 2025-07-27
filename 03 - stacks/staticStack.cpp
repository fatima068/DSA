// push, pop, is full, is empty, peek
#include <iostream>
using namespace std;

class Stack {
    private:
    int top;
    int capacity;
    int* arr;

    public:
    Stack(int capacity) : capacity(capacity), top(-1) {
        arr = new int[capacity];
    }

    void push(int val) {
        if (isFull()) {
            cout << "stack full, cannot push " << val << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    void pop() {
        if (isEmpty() == true) {
            cout << "stack empty, cannot pop" << endl;
            return;
        }
        cout << "popping " << arr[top] << endl;
        top--;
    }

    bool isEmpty() {
        if (top == -1) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (top == capacity - 1) {
            return true;
        }
        return false;
    }

    // returns the element at the given position (starting from bottom of stack)
    int peek(int position) {
        if (isEmpty() == true) {
            cout << "stack empty, peek operation failed" << endl;
            return -1;
        }
        if (position > top+1 || position < 1) {
            cout << "invalid position, peek failed" << endl;
            return -1;
        }
        cout << "value at " << position << ": " << arr[position - 1] << endl;
        return arr[position - 1];
    }

    void print() { // iss mei bottom to top print horha hai, ulta hona chaiye (top waala element pehle print hona chahiye)
        if (isEmpty() == false) {
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << "  ";
            }
        }
        cout << endl;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack stack(5);
    stack.push(5);
    stack.push(4);
    stack.push(3);
    stack.push(2);
    stack.push(1);

    stack.peek(2);

    stack.print();
}