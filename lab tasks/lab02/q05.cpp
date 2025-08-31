// Write a C++ program that dynamically creates a 2D matrix and provides:
// => Addition of two matrices.
// => Subtraction of two matrices.
// => Ensure safe memory handling with proper allocation/deallocation.

#include <iostream>
using namespace std;   

int** addMatrix(int** m1, int** m2, int rows,int cols){
    int **ans = new int*[rows];
    for (int i=0; i <rows; i++) {
        ans[i] = new int[cols];
    }
    for (int i=0; i< rows; i++) {
        for (int j = 0; j < cols; j++ ){
            ans[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return ans;
}

int** subtractMatrix (int** m1,int** m2, int rows,int  cols) {
    int **ans = new int*[rows];
    for (int i=0; i <rows; i++) {
        ans[i] = new int[cols];
    }
    for (int i=0; i< rows; i++) {
        for (int j = 0; j < cols; j++ ){
            ans[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return ans;
}


void print(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
}

int main(){
    int choice, rows, cols;
    cout << "enter 1 for addition, 2 for subtraction: ";
    cin >> choice;
    cout << "enter rows of matrix: ";
    cin>>rows;
    cout <<"enter cols of matrix: ";
    cin>>cols;

    int **matrix1 = new int*[rows], **matrix2 = new int*[rows], **result; //because both matrices need to have same rows and cols for addition and subtraction
    for (int i =0;i < rows; i++) {
        matrix1[i] = new int[cols];
        matrix2[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "enter matrix1[" << i << "][" << j << "] : ";
            cin >> matrix1[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "enter matrix2[" << i << "][" << j <<"] : ";
            cin >> matrix2[i][j];
        }
    }

    if (choice == 1) {
        cout << "addition\n";
        result = addMatrix(matrix1, matrix2, rows, cols);
        print(matrix1, rows, cols);
        print(matrix2, rows, cols);
        print(result, rows, cols);
    } else if (choice == 2){
        cout << "subtractionn\n";
        result = subtractMatrix(matrix1, matrix2, rows, cols);
        print(matrix1, rows, cols);
        print(matrix2, rows, cols);
        print(result, rows, cols);
    }

    for (int i=0; i<rows; i++) {
        delete[] matrix1[i];
        delete[] matrix2[i];
        delete[] result[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] result;
}