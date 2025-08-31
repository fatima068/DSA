// Implement a program to represent a sparse matrix using a dynamic 2D array.
// => Input matrix elements.
// => Display the matrix in normal form.
// => Display the matrix in compressed form (row, column, value).
#include <iostream>
using namespace std;

int main() {
    int **arr;
    int rows,cols;
    cout << "enter rows: ";
    cin >> rows;
    cout << "enter cols: ";
    cin >> cols;
    arr = new int*[rows];
    for (int i=0; i < rows; i++){
        arr[i] = new int[cols];
    }
    cout << "input elements:" <<endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << "arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
    cout << "normal form:" << endl;
    for(int i =0; i< rows; i++){
        for(int j=0; j< cols; j++){
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "compressed form:" << endl;
    cout << "row\tcol\tvalue"<< endl;
    for (int i=0; i < rows; i++) {
        for (int j=0; j < cols; j++){
            if(arr[i][j] != 0) {
                cout << i << "\t" << j << "\t" << arr[i][j] << endl;
            }
        }
    }
    for (int i =0; i < rows; i++){
        delete[] arr[i];
    }
    delete[] arr;
}
