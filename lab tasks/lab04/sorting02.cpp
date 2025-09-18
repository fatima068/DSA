// 2.   You are tasked with implementing the Shell Sort algorithm to sort the weights of employees in 
// a company. However, instead of using the traditional gap sequence (where the gap is divided by 2), 
// you must create and implement a custom gap sequence of your choice that you think can align with 
// the problem.
#include <iostream>
using namespace std;

void shellSortCustom(int arr[],int n){
    for (int gap=n/3+1; gap>0;gap =(gap==1?0:gap/3)){ //used gap smaller than n/2 to make it more effeicient
        for (int i= gap;i<n; i++) {
            int temp=arr[i];
            int j;
            for (j=i; j>=gap && arr[j-gap] >temp; j-=gap) {
                arr[j] =arr[j-gap];
            }
            arr[j]=temp;
        }
        if (gap== 1) break; 
    }
}

int main() {
    int weights[] = {75,60,82,55,90,68,72};
    int n= 7;
    cout<< "unsorted: ";
    for(int i = 0; i < n; i++) 
    cout<<weights[i] << " ";
    cout <<endl;
    shellSortCustom(weights,n);
    cout <<"sorted: ";
    for (int i =0; i <n;i++) cout <<weights[i] <<" ";
}
