// Q3. Create a C++ class Box that uses dynamic memory allocation for an integer. Implement the Rule of Three by defining a destructor, copy constructor, and copy assignment operator. Demonstrate the behavior of both shallow and deep copy using test cases.

#include <iostream>
using namespace std;

class Box{
    public:
    int *size;

    Box(int s){ size = new int(s); } // parameterized constructor

    Box(const Box &b1) {
        size = new int;
        *size = *b1.size;
    }

    Box& operator=(const Box &b1){
        delete size;
        size = new int;
        *size = *b1.size;
        return *this;   
    }

    void print() { cout << *size << endl; }

    ~Box(){ delete size;}
};

int main(){
    Box b1(1);
    Box b2(2); 
    cout << "b1 = ";
    b1.print();
    cout << "b2 = ";
    b2.print();
    b2 =  b1;
    cout << "after assigning b1 to b2, b2 = ";
    b2.print(); 
    cout << "if copy constructor and copy assignment operator were not created, then both b1 and b2 would have pointed to the same memory location, leading to issues like double deletion when both destructors are called";
    b1.size = new int(5);
    cout << endl << "b1 val changed, now b1 = ";
    b1.print();
    cout << "b2 remains unchanged = ";
    b2.print();
    cout << "if deep copy was not implemented, changing b1 would have also changed b2 as both would have pointed to the same memory location";
}