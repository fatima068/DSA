// 1.   Implement the bubble sort algorithm to sort the in descending order (starting from the initial 
// pass). Take array [10] = {5,1,3,6,2,9,7,4,8,10}. You can also take your array as user input.
#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i= 0;i<n-1; i++) {
        bool swapped = false; 
        for (int j= 0; j< n-i-1; j++) {
            if (arr[j] <arr[j+1]){
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
int main(){
    int arr[] = {5,1,3,6,2,9,7,4,8,10};
    cout<<"unsorted array: ";
    print(arr,10);
    bubbleSort(arr,10);
    cout<<endl<<"sorted array: ";
    print(arr,10);
}