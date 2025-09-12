
#include <iostream>
using namespace std;
void insertionSort(int arr[], int n) {
    for (int i = 1; i<n; i++) {
        int current = arr[i];
        int prev = i - 1; 
        while (prev >=0 && arr[prev] < current) { 
            arr[prev + 1] = arr[prev]; 
            prev--;
        }
        arr[prev + 1] = current;
    }
}

int main() {
    int CEO = 0, CTO = 1, CFO = 2, VP = 3, MGR = 4, EMP = 5;
    int n = 8;
    int*arr = new int[8];
    arr[0]=EMP;
    arr[1]=CFO;
    arr[2]=MGR;
    arr[3]=EMP;
    arr[4]=VP;
    arr[5]=CTO;
    arr[6]=MGR;
    arr[7]=CEO;

    insertionSort(arr, n);
    
    cout << "sorted array:" << endl;
    for(int i=0; i < n; i++) {
        string val=(arr[i]==0) ? "CEO" : (arr[i]==1)? "CTO" : (arr[i]==2) ? "CFO" : (arr[i]==3) ? "VP" : (arr[i]==4) ? "MGR": "EMP";
        cout << val << endl;
    }
}