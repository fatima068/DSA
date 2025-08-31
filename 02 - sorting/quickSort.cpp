#include <iostream>
using namespace std;

// there are 3 types of quick sort: pivot at start, pivot at end, pivot at random position: we are doing the one with pivot at the end 

int partition(int arr[], int start, int end) { 
    int pivot = arr[end];
    int pivotIndex = start;
    for (int i = start; i < end; i++) {
        if (arr[i] < pivot) {
            // swap(arr[i], arr[pivotIndex]);
            int temp = arr[i];
            arr[i] = arr[pivotIndex];
            arr[pivotIndex] = temp;

            pivotIndex++;
        }
    }
    //swap(arr[pivotIndex], arr[end]);
    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[end];
    arr[end] = temp;
    return pivotIndex;
}

void quickSort(int arr[], int start, int end) {
    if (start < end) {
        int p = partition(arr, start, end);
        quickSort(arr, start, p -1);
        quickSort(arr, p + 1, end);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i<n; i++) {
        cout << arr[i] << "   ";
    }
}

int main() {
    int arr[] = {5, 6, 2, 9, 7, 6};
    quickSort(arr, 0, 5);
    printArray(arr, 6);
}