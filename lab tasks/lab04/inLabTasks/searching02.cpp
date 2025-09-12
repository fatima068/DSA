// You've been given an array of numbers representing employee IDs. Your task is to identify the employee whose ID matches the last two digits of your roll number. If your roll number's last two digits are not present in the array, insert the missing value in its correct position within the array. You must use binary search to locate the position of that value within the array.
#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left<= right) {
        int mid=left +(right - left) /2 ;
        if (arr[mid] ==target){
            return mid;
        } else if (arr[mid]<target) {
            left= mid+1;
        } else 
            right= mid-1;
    }
    return -1;
}

void print(int arr[], int n){
    for(int i=0;i <n; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}


int main(){
    int n,rollnumber = 24;
    int pos;
    cout <<"enter number of employees : ";
    cin>> n;

    int* arr= new int[n];
    int* newarr = nullptr;
    for(int i=0;i<n; i++) {
        cout<<"employee id " << i << " (ascending order): ";
        cin>>arr[i];
    }
    cout << "original array: ";
    print(arr, n);
    pos= binarySearch(arr, n, rollnumber);
    if(pos == -1){
        cout <<" employee not found so we will insert rollnumber in array" << endl;
        int insertPos = 0;
        while (insertPos<n && arr[insertPos]<rollnumber){
            insertPos++;
        }
        int* newarr = new int[n+1];
        for(int i=0;i<insertPos;i++) {
            newarr[i] =arr[i];
        }
        newarr[insertPos] = rollnumber;
        
        for(int i = insertPos; i < n; i++) {
            newarr[i+1]= arr[i];
       }
        delete[] arr;
        arr =newarr;
        n =n++;
        cout << "new array after adding roll num: ";
        print(arr, n);

    } else{
        cout <<"employee found at index" << pos << endl;

    }
    delete[] arr;
    delete[] newarr;

}