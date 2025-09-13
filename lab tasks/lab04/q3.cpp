// Implement the Selection Sort algorithm. The program should take an array of integers from the user, find the smallest element, and exchange it with the element at the first position. This process should continue until the array is completely sorted. Display the sorted array to the user.
#include <iostream>
using namespace std;

void print(int arr[],int n){
    for(int i = 0; i<n;i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}


void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int smallestIndex = i;
        for (int j = i+1; j<n; j++) {
            if (arr[j] < arr[smallestIndex]) {
                smallestIndex = j; 
            }

        }
        int temp= arr[i]; 
        arr[i]= arr[smallestIndex];
        arr[smallestIndex]= temp;
    }
}

int main() {
    int n;
    cout<<"what is array size? ";
    cin>> n;
    int* arr=new int[n];
    cout << "input elements here: " <<endl;
    for (int i = 0; i < n; i++)   cin>>arr[i];
    cout << "unsorted: ";
    print(arr, n);
    selectionSort(arr, n);
    cout <<"sorted : ";
    print(arr, n);

    delete[] arr;
}


