#include <iostream>
using namespace std;    

void insertionSortRecursive(int arr[], int n) {
    if (n <= 1) return; // if array has 0 or 1 element, it's already sorted

    // Sort first n-1 elements
    insertionSortRecursive(arr, n-1);

    //the code below this recursive call runs first when only 2 elemnts are in the array. jab wo sort hojayenge tou yeh code 3 elements ke liye run hoga (with first 2 sorted and last one unsorted) and so on...

    int last = arr[n-1]; // arr ka size - 1 gives u last element (jisko sahi position mei insert karna hai)
    int prev = n-2; // index of last element in sorted part

    while (prev >= 0 && arr[prev] > last) { // inserting the last (unsorted) element into its correct position in the sorted part by traversing the sorted part from right to left
        arr[prev+1] = arr[prev];
        prev--;
    }

    arr[prev+1] = last; // place last/unosrted element at its correct position
}

int findMinIndex(int arr[], int start, int n) {
    int smallestIndex = start;
    for (int i = start+1; i < n; i++) {
        if (arr[i] < arr[smallestIndex]) {
            smallestIndex = i;
        }
    }
    return smallestIndex;
}

void selectionSortRecursive(int arr[], int start, int n) {
    if (start >= n-1) return; // last element is already sorted (largest element hee end pe hoga) so if start of unsorted array = last element of the array, dont call sorting function

    int minIndex = findMinIndex(arr, start, n); // start is basically where the unsorted part starts
    // so unsorted array ka smallest element find karke, usko unsorted array ke first element se swap karna hai
    if (minIndex != start) {
        int temp = arr[start];
        arr[start] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // call selection sort on the remaining unsorted array
    selectionSortRecursive(arr, start+1, n);
}

void combSortRecursive(int arr[], int n, int gap, bool swapped) { // in the main, gap ko n pass karden ge 
    // If gap is 1 and no swaps that means array is sorted
    if (gap == 1 && !swapped) return;

    // Shrink the gap
    float shrinkFactor = 1.3;
    gap = int(gap / shrinkFactor);
    swapped = false;
    if (gap < 1) gap = 1;

    // One pass with current gap
    for (int i = 0; i + gap < n; i++) {
        if (arr[i] > arr[i+gap]) {
            //swap(arr[i], arr[i+gap]);
            int temp = arr[i];
            arr[i] = arr[i+gap];
            arr[i+gap] = temp;
            swapped = true;
        }
    }

    // Recurse with new gap on the same array 
    combSortRecursive(arr, n, gap, swapped); // swapped is being passed as parameter because if iss run mei no swaps were performed then swap will be false and in the next recursve call, if swapped is false then wahin pe code exit hojayega because swapped false means array has been sorted 
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSortRecursive(int arr[], int n) {
    // Base case: array of size 0 or 1 is already sorted
    if (n <= 1) return;

    // One pass of bubble sort: move the largest element to the end
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    // Largest element is now fixed at arr[n-1]
    // Recur for remaining array of size n-1
    bubbleSortRecursive(arr, n - 1);
}

