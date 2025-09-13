// Implement the Comb Sort algorithm to sort an array of integers. This algorithm improves upon bubble sort by reducing the number of comparisons and swaps using a "gap" that decreases over time. After sorting, perform a complexity analysis: count and display the total number of swaps and comparisons performed during the sorting process.
#include <iostream>
using namespace std;

void combSort(int arr[],int n, int&swaps, int&comparisons) {
    float shrink=1.3;
    int gap=n;
    bool swapped =true;
    swaps=0;
    comparisons=  0;

    while (gap >1 ||swapped ==true) {
        gap = int(gap / shrink);
        if (gap< 1)
            gap= 1;
        swapped = false;

        for (int i = 0; i + gap < n; ++i) {
            comparisons++;
            if (arr[i]>arr[i+gap]) {
                int temp=arr[i];
                arr[i] =arr[i+ gap];
                arr[i+ gap] =temp;
                swaps++;
                swapped = true;
            }
        }
    }
}
void print(int arr[],int n){
    for(int i = 0; i<n;i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main() {
    int n, swaps, comparisons;
    cout<<"what is array size? ";
    cin>> n;
    int* arr=new int[n];
    cout << "input elements here: " <<endl;
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    cout << "u nsorted : ";
    print(arr, n);
    combSort(arr, n, swaps, comparisons);
    cout << "sorted:" ;
    print(arr,n);
    cout << "swaps= " <<swaps << ", comparisons = " << comparisons;
}