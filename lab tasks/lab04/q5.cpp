// Implement the Interpolation Search algorithm. The program should take a sorted array with uniformly distributed values and a target value from the user. The algorithm should estimate the position of the target and check if the estimated position holds the correct value. If the element is found, print its index; otherwise, indicate that it's not present.
#include <iostream>
using namespace std;

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
    cout<<"enter array in ascending order" << endl;
    for(int i=0;i< n;i++) { 
        cout<< "enter value " << i<<": ";
        cin>>arr[i];
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