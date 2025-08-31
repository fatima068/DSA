/*Task #6:
Implement a Safe Pointer class to wrap around an integer pointer.
=> Provide methods for setValue(), getValue(), and release().
=> Demonstrate the class by storing marks of 5 students and printing them safely without direct pointer manipulation.*/

#include <iostream>
using namespace std;

class SafePointer { 
    int *arr;
    int size;
    int currIndex; //so we can push the elements instead of askign user for index everytime

    public:
    SafePointer(int size) : size(size) { 
        arr = new int[size];
        currIndex = -1; 
    }

    void setValue() {
        cout << "enter value: "; 
        currIndex++; 
        if (currIndex==size) {
            cout << "array full" << endl;
            return;
        }
        cin >> arr[currIndex];
    }

    int getValue() {
        int i;
        cout << "enter index to get value: ";
        cin >> i;
        if(i>=0 && i<=currIndex) {
            return arr[i];
        } else {cout << "invalid index val" <<endl; return -1; }
    }

    void release() {
        delete[] arr;
        arr = nullptr;
        cout << "memory released" << endl;
    }

    void print(){
        for (int i=0; i< size; i++) {
            cout << arr[i] << " ";
        }
        cout <<endl;
    }

    ~SafePointer() {
        if(arr!=nullptr) 
            delete[] arr;
    }
};

int main(){
    int n;
    cout << "how many students makrs to store in array? ";
    cin >> n;
    SafePointer arr(n);
    for (int i=0; i<n; i++) {
        arr.setValue();
    }
    arr.print();
    cout << arr.getValue() << endl;
    cout << arr.getValue()<< endl;
    arr.release();
}