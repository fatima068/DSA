#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int leftIndex = l, tempIndex = l, rightIndex = m + 1; // left index does not start from 0
    int n = (r - l) + 1; // cannot pass n as paramter kyunke har recursive call mei array ka size alag hai
    int *temp = new int[n];
    while (leftIndex <= m && rightIndex <= r) {
        if (arr[leftIndex] < arr[rightIndex]) {
            temp[tempIndex] = arr[leftIndex];
            leftIndex++;
            tempIndex++;
        }
        else {
            temp[tempIndex] = arr[rightIndex];
            rightIndex++;
            tempIndex++;
        }
    }
    while (leftIndex <= m) {
        temp[tempIndex] = arr[leftIndex];
        tempIndex++;
        leftIndex++;
    }
    while (rightIndex <= r) {
        temp[tempIndex] = arr[rightIndex];
        tempIndex++;
        rightIndex++;
    }
    // for (int i = 0; i < n; i++) { // size of array is not always n and doesnt always start from 0, so this will be wrong
    //     arr[i] = temp[i];
    // }
    for (int i = l; i <= r; i++) { // shpuldnt be < r as r is included
        arr[i] = temp[i];
    }
    delete[] temp; //dont use delete because its an array allocated using new[]
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    mergeSort(arr, 0, 6);
    cout << "Sorted array using merge Sort: ";
    printArray(arr, 7);
}