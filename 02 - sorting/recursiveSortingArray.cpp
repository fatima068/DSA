#include <iostream>
using namespace std;    

void insertionSortRecursive(int arr[], int n) {
    // Base case
    if (n <= 1) return;

    // Sort first n-1 elements
    insertionSortRecursive(arr, n-1);

    // Insert the nth element into correct position
    int last = arr[n-1];
    int j = n-2;
    while (j >= 0 && arr[j] > last) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int findMinIndex(int arr[], int start, int n) {
    int minIndex = start;
    for (int i = start+1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

void selectionSortRecursive(int arr[], int start, int n) {
    // Base case
    if (start >= n-1) return;

    // Find minimum in [start ... n-1]
    int minIndex = findMinIndex(arr, start, n);

    // Swap with first element
    if (minIndex != start) {
        int temp = arr[start];
        arr[start] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Recur for remaining part
    selectionSortRecursive(arr, start+1, n);
}

void combSortRecursive(int arr[], int n, int gap, bool swapped) {
    // If gap is 1 and no swaps → sorted
    if (gap == 1 && !swapped) return;

    // Shrink the gap
    int shrinkFactor = 13; // means 1.3 (integer division trick)
    gap = (gap * 10) / shrinkFactor;
    if (gap < 1) gap = 1;

    swapped = false;

    // One pass with current gap
    for (int i = 0; i + gap < n; i++) {
        if (arr[i] > arr[i+gap]) {
            int temp = arr[i];
            arr[i] = arr[i+gap];
            arr[i+gap] = temp;
            swapped = true;
        }
    }

    // Recurse with new gap
    combSortRecursive(arr, n, gap, swapped);
}