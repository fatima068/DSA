// Write a C++ program to implement Linear Search. Your program should take an array of integers and a target value as input from the user. The program should search for the target value in the array using the linear search algorithm and output the index at which the target is found. If the target value is not found in the array, the program should display an appropriate message.
#include<iostream>
using namespace std;

int linearsearch(int arr[], int target, int n) {
    for(int i=0;i<n;i ++) {
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    int* arr;
    int n, target;
    cout<<"size of array? ";
    cin>>n;
    arr=new int[n];
    for(int i =0;i<n; i++) {
        cout << "enter val " << i <<": ";
        cin>>arr[i];
    }
    cout<<"enter value to search in arry: ";
    cin>> target;
    int ans = linearsearch(arr, target, n);
    if (ans == -1) {
        cout <<"target value not foudn";
    }
    else cout<<"target val found at index: " << ans << endl;
    delete[] arr;
}