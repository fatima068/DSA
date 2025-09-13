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

void insertionSort(int arr[], int n,int &insertionSwaps,int& insertionComparsions) {
    for (int i = 1; i < n; i++) {
        int current= arr[i];
        int prev = i -1;
        while (prev >= 0) {
            insertionComparsions++;
            if (arr[prev] > current) {
                arr[prev + 1] = arr[prev];
                insertionSwaps++;
                prev--;
            } else {break;}
        }
        arr[prev + 1] = current;
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