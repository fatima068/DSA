// Write a program to implement the Bubble Sort algorithm. The program should take an array of integers as input from the user, sort the array using bubble sort, and then display both the unsorted and sorted arrays.
#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n);
void print(int arr[],int n);

int main() {
    int n;
    cout << "enter array sizee: ";
    cin >> n;
    int arr[n];
    cout << "input elements: "<< endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "unsorted: ";
    print(arr, n);
    bubbleSort(arr, n);
    cout << "sorted : ";
    print(arr, n);

}

void bubbleSort(int arr[],int n) {
    for (int i = 0; i < n-1; i++) {
        bool swapped = false; 
        for (int j = 0;j< n-i-1; j++) {
            if (arr[j]> arr[j+1]){
                int temp= arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped= true;
            }
        }
        if (swapped== false) { 
            return;
        }
    }
}
void print(int arr[],int n){
    for(int i = 0; i<n;i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

