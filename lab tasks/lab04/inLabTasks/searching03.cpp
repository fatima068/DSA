// Your team has been given a large dataset (input by user) of sorted, uniformly distributed account balances. If the data is not sorted, you have to sort it first. If the data is not uniformly distributed after you apply sorting (if necessary) you can prompt an error. Your manager has asked you to implement Interpolation Search because it estimates the position of the target value based on the data distribution. This will allow the search to "jump" closer to the target in fewer iterations.

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i= 0;i<n-1; i++) {
        bool swapped = false; 
        for (int j= 0; j< n-i-1; j++) {
            if (arr[j] >arr[j+1]){
                int temp =arr[j];
                arr[j] =arr[j+1];
                arr[j+1]=temp;
                swapped=true;
            }
        }
        if (swapped==false){
            return;
        }
    }
}

void print(int arr[], int n){
    for(int i =0; i<n; i++) {
        cout<<arr[i] <<"  ";
    } 
    cout << endl;
}

bool isSorted(int* arr, int n) {
    bool sorted = true;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            sorted = false;
        }
    }
    return sorted;
}

int interpolationSearch(int array[], int sizeOfArray, int valueToSearch) {
    int low= 0;
    int high= sizeOfArray-1;

    while (valueToSearch <= array[high] && valueToSearch >= array[low] && low <= high) {
        int probe = low + (high - low) * (valueToSearch - array[low]) / (array[high] - array[low]);
        if (array[probe] == valueToSearch) {
            return probe;
        }else if (array[probe]< valueToSearch) {
            low = probe + 1;
        }else high = probe - 1;
    }
    return -1;
}

int main(){
    int n;
    int *arr;
    cout<<"enter size of arry: ";
    cin >>n;
    arr= new int[n];
    for(int i=0;i< n;i++) { 
        cout<< "enter value " << i<<": ";
        cin>>arr[i];
    }

    bool x = isSorted(arr, n);
    if(x==false){
        bubbleSort(arr, n);
        cout<<"Sorted array: "; print(arr,n);
    }


    int diff=arr[1]-arr[0];
    for(int i =1; i<n-1; i++){ //check here if array is uniform distributed
        if((arr[i+1]-arr[i])!=diff){
            cout << "error : data not uniformly distributed";
            exit(0);
        }
    }
    int target;
    cout<<"enter value to search in ur array: ";
    cin>>target;
    int pos = interpolationSearch(arr, n, target);
    if(pos == -1) {
        cout << "target val not found";
    } else {
        cout <<"target val fpund at index" << pos << endl;
    }

    delete[]arr;

    
}