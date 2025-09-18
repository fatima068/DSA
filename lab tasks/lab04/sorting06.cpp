
// 6.   A clerk at a shipping company is charged with the task of rearranging a number of large crates 
// in order of the time they are to be shipped out. Thus, the cost of compares is very low relative to 
// the cost of exchanges (move the crates). The warehouse is nearly full: there is extra space 
// sufficient to hold any one of the crates, but not two. Which sorting method should the clerk use? 
// Implement this question via a user generated array?
#include <iostream>
using namespace std;
//the clerk should use insertion sort bcz it minimizes num of exchanges needed to sort 

void insertionSort(int arr[], int n) {
    for (int i=1;i<n;i++){
        int key=arr[i];
        int j =i-1;
        while(j >= 0 && arr[j]>key){
            arr[j+1] =arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int n;
    cout <<" num of crates?? ";
    cin>>n;
    int* crates = new int[n];
    for(int i= 0;i<n; i++){
        cout << " shipping time for crate " << i+1 << ": ";
        cin >> crates[i];
    }
    cout << "unsorted: ";
    for (int i=0;i<n;i++)
        cout<<crates[i]<< " ";
    cout <<endl;
    insertionSort(crates,n);
    cout << "sorted: ";
    for (int i = 0; i< n; i++) 
        cout <<crates[i] << " ";

    delete[] crates;

}