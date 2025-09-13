/*4. Use Insertion Sort to sort an array of integers provided by the user. Then, implement the
Binary Search algorithm to find a target value within the newly sorted array. The program
should display the sorted array and the index of the found element or a message if it's not
present.*/

#include <iostream>
using namespace std;
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int current= arr[i];
        int prev = i -1;
        while (current < arr[prev] && prev >= 0) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = current;
    }
}

int binarySearch(int arr[], int n, int target) {
    int left=0;
    int right= n - 1;
    while (left<= right) {
        int mid= left+ (right-left)/2;
        if (arr[mid] == target){
            return mid; 
        } else if (arr[mid] < target) {
            left = mid + 1;
        }
        else 
            right = mid - 1;
    }
    return -1; 
}
void print(int arr[],int n){
    for(int i = 0; i<n;i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main() {
    int n;
    cout<<"what is array size? ";
    cin>> n;
    int* arr=new int[n];
    cout << "input elements here: " <<endl;
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    cout << "u nsorted : ";
    print(arr, n);
    insertionSort(arr, n);
    cout << "sorted:" <<endl;
    print(arr,n);

    int target;
    cout << "enter target: ";
    cin >> target;
    int search = binarySearch(arr,n, target);

     if (search == -1) {
        cout << "not found"<<endl;
    } else  cout << "index: "<< search<<endl;
    delete []arr;
}