#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        bool swapped = false; 
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if (swapped == false) { // this means ke outer loop ek baar run hogya, but kuch bhi swap nai hua, so array is already sorted and there is no need to run the sort function again, we can just return
            return;
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int smallestIndex = i;
        for (int j = i+1; j < n; j++) { //i is where the sorted part ends, so we assume i+1 is the first and smallest element, then comapre it with entire unsorted array to find index of smallest element. Then swap it with the first element of unsorted array
            if (arr[j] < arr[smallestIndex]) {
                smallestIndex = j; 
            }
        }
        //swap(arr[i], array[smallestIndex]);
        int temp = arr[i]; 
        arr[i] = arr[smallestIndex];
        arr[smallestIndex] = temp;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i<n; i++) { //start with i = 1 because 0th element is already assumed to be sorted, we need to start checking from the 1st element
        int current = arr[i];
        int prev = i - 1; // this is the index of the last element of the sorted part 
        while (prev >=0 && arr[prev] > current) { // if the current element is smaller than the last element of the sorted part, we need to shift the last element to the right
            arr[prev + 1] = arr[prev]; 
            prev--;
        }
        arr[prev + 1] = current; // place the current element in its correct position in the sorted part
    }
}

void shellSort(int arr[], int n) {

}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    insertionSort(arr, 7);
    cout << "Sorted array using selection Sort: ";
    printArray(arr, 7);
}