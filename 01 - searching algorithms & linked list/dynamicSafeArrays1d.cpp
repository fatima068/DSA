// A safe array example.
#include <iostream>
#include <cstdlib>
#include<string.h>
using namespace std;


class safeArray {
    private:
    int ncols; // as it is a 1d array, this is basically number of elements in the array
    int *dynamicArray; //Pointer to the dynamically allocated integer array

    public:
        // Default Constructor to create an empty array
        safeArray() : ncols(0), dynamicArray(NULL) {} // Initialize ncols to 0 and dynamicArray to NULL

        //Paramatrized Constructor to create array of given size 
        safeArray (int col) : ncols(col) {
            dynamicArray = new int[ncols]; //allocating memory according to the size specified
        }
        
        //copy constructor (rule of 3 implementation)
        safeArray (const safeArray & rhs) {
            ncols = rhs.ncols;
            dynamicArray = new int[ncols];
            // memcpy(destination, source, sizeof(source));
            // copy all bytes of destination to source
            memcpy(dynamicArray,rhs.dynamicArray, sizeof(int)*ncols); 
            // Copies raw bytes - Treats memory as a sequence of bytes
            // Copies the values - For an int array, copies the actual integer values
            // Doesn't copy addresses - The pointer values themselves aren't copied, just what they point to
        }

        //destructor
        ~safeArray (){
            delete [] dynamicArray; //free allocated memory
            dynamicArray=NULL; // prevent dangling pointer: not a necessary step but a good practice
            // don't need to set ncols = 0 in the destructor because the object is being destroyed anyway - After the destructor runs, the object's memory will be reclaimed, including all member variables (ncols and dynamicArray). Setting ncols to 0 would be pointless
        }


        // Allows user to input values for each array element
        // Uses bounds-checked loop to ensure safety
        void fillArray() {
            for (int i=0; i<ncols; ++i){
                int value;
                cout<<"enter value";
                cin>>value;
                dynamicArray[i] = value; // it takes all values ek hee loop mei, tou jo array ka size hai, utni hee values daalni paregi when u call this function. U cant just put 2 elements in a 5 element array
            }
        }

        // provides bound checking before accessing array 
        int &operator[] (int i) {
            if(i<0 || i>ncols-1 ) {
                cout << "Boundary Error\n";
                exit(1);
            }
            return dynamicArray[i];
        }

        //assignment operator
        safeArray &operator= (const safeArray & rhs) {
            // 1. Self-assignment check (ob1 = ob1 tou nai kiya?)
            if (this == &rhs)
                return *this;

            // 2. Clean up existing resources
            delete[] dynamicArray;
            dynamicArray = NULL;
            
            // 3. Copy the size
            ncols = rhs.ncols;
            
            // 4. Allocate new memory and copy data
            dynamicArray = new int[ncols];
            memcpy(dynamicArray, rhs.dynamicArray, sizeof(int)*ncols);

            // 5. Return reference to self
            return *this;
        }
};

int main() {
    // 1. Get array size from user
    int columns;
    cout << "enter cols" << endl;
    cin >> columns;
    
    // 2. Create first safeArray object
    safeArray ob1(columns);
    
    // 3. Fill the array with user input
    ob1.fillArray();
    
    // 4. Create a copy using copy constructor
    safeArray ob2 = ob1;
    
    // 5. Access and print elements
    cout << ob1[1] << endl;    // Valid access
    cout << ob2[4] << endl;    // Testing bounds checking
}