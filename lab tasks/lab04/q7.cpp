// Implement the Shell Sort algorithm to sort an array of integers. The algorithm should start with a large gap, then perform a gapped insertion sort, and gradually reduce the gap until it's 1. After sorting, compare its performance against the Bubble Sort and Insertion Sort algorithms for the same input array size (e.g., 1000 elements). Record and display the time taken and the number of comparisons/swaps for all three algorithms to demonstrate why Shell Sort is an improvement over Insertion Sort.
#include<iostream>
using namespace std;

void shellSort(int arr[],int n,int &shellSwaps,int& shellComparsions){
    for (int gap = n/2; gap > 0; gap/=2) {
        for (int j = gap; j < n; j++) {
            int temp = arr[j];
            int i = j;

            while (i >= gap) {
                shellComparsions++; 
                if (arr[i-gap] >temp) {
                    arr[i]=arr[i-gap];
                    shellSwaps++;
                    i-=gap;
                } else break;
            }
            arr[i] = temp;
        }
   }
}

void combSort(int arr[], int n, int&swaps, int&comparisons) {
    float shrink = 1.3;
    int gap = n;
    bool swapped = true;
    swaps = 0;
    comparisons = 0;

    while (gap > 1 || swapped == true) {
        gap = int(gap / shrink);
        if (gap < 1) {
            gap = 1;
        }
        swapped = false;

        for (int i = 0; i + gap < n; i++) {
            comparisons++;
            if (arr[i] > arr[i + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swaps++;
                swapped = true;
            }
        }
    }
}


void bubbleSort(int arr[], int n, int &bubbleSwaps,int& bubbleComparsions) {
    for (int i = 0; i<n-1; i++) {
        bool swapped= false; 

        for (int j=0;j<n-i-1;j++) {
            bubbleComparsions++;
            if (arr[j] >arr[j+1]){
                int temp =arr[j];
                arr[j] =arr[j+1];
                arr[j+1]=temp;
                bubbleSwaps++;
                swapped =true;
            }
        }
        
        if (swapped == false) {
            return;
        }
    }
}

void insertionSort(int arr[], int n, int &insertionSwaps, int& insertionComparsions) {
    for (int i = 1; i < n; i++) { //start with i = 1 because 0th element is already assumed to be sorted, we need to start checking from the 1st element
        int current = arr[i]; // value store karni hai, not the index kyunke index tou over write hojayega when prev ko aage move karenge 
        int prev = i - 1; // this is the index of the last element of the sorted part 

        while (prev >= 0) { // if the current element is smaller than the last element of the sorted part, we need to shift the last element to the right
            insertionComparsions++;
            if (arr[prev] > current) {
                arr[prev + 1] = arr[prev];
                insertionSwaps++;
                prev--;
            } else break;
        }

        arr[prev + 1] = current; // place the current element in its correct position in the sorted part
    }
}

void selectionSort(int arr[], int n, int &swaps, int &comparisons) {
    swaps = 0;
    comparisons = 0;

    for (int i = 0; i < n - 1; i++) { // runs till n - 1 because last element will already be sorted when all other elements are sorted
        int smallestIndex = i;

        for (int j = i + 1; j < n; j++) { //i is where the sorted part ends, so we assume i+1 is the first and smallest element, then comapre it with entire unsorted array to find index of smallest element. Then swap it with the first element of unsorted array
            comparisons++;
            if (arr[j] < arr[smallestIndex]) {
                smallestIndex = j;
            }
        }
        if (smallestIndex != i) { // only swap if the smallest index is not the current index
            int temp = arr[i];
            arr[i] = arr[smallestIndex];
            arr[smallestIndex] = temp;
            swaps++;
        }
    }
}



 int main(){
    const int n = 5000;
    int arr[n],arr2[n],arr3[n];
    int shellSwaps = 0, shellComparsions = 0,bubbleSwaps = 0, bubbleComparsions = 0,insertionSwaps = 0, insertionComparsions = 0;
    srand(time(0));
    for (int i=0;i< n;i++) {
        arr[i] =rand();
        arr2[i] =arr[i];
        arr3[i]=arr[i];
    }


    clock_t start, end;
    start= clock();
    shellSort(arr, n, shellSwaps, shellComparsions);
    end= clock();
    double shellTime =double(end-start)/CLOCKS_PER_SEC;

    start= clock();
    bubbleSort(arr2, n, bubbleSwaps, bubbleComparsions);
    end= clock();
    double bubbleTime =double(end-start)/CLOCKS_PER_SEC;

    start= clock();
    insertionSort(arr3, n, insertionSwaps, insertionComparsions);
    end= clock();
    double insertionTime =double(end-start)/CLOCKS_PER_SEC;
    cout << "shell Sort time= "<<shellTime << ", comparisons= " << shellComparsions << ", swaps= "<<shellSwaps << endl;
    cout << "bubble Sort time= "<<bubbleTime << ", comparisons= " << bubbleComparsions << ", swaps= "<<bubbleSwaps << endl;
    cout << "insertion Sort time= "<<insertionTime << ", comparisons= " << insertionComparsions << ", swaps= "<<insertionSwaps << endl;
 }