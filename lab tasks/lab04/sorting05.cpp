// 5.   Develop C++ solution such that day month and year are taken as input for 5 records and perform 
// Sorting Dates based on year using Selection Sort. Note: Input must be taken from user.
// [Hint: Struct or Class can be used]
// It's not strictly necessary to take inputs in the format as shown in example, but, the output 
// should be in the given format.

// Example Input:
// 01/02/2022
// 5/01/2018
// 4/07/2015
// 12/10/2021
// 11/12/2023

// Example Output:
// 4/07/2015
// 5/01/2018
// 12/10/2021
// 01/02/2022
// 11/12/2023
#include<iostream>
using namespace std;

class date{
    public:
    int day, month,year;

    date():day(0), month(0), year(0){}
    date(int day, int month, int year): day(day), month(month), year(year){}

    void print(){
        cout<<day<<"/"<< month<<"/" << year << endl;
    }
};

void selectionSort(date arr[], int n){
    for (int i = 0; i< n-1; i++) {
        int smallestIndex=i;
        for (int j=i+1;j <n;j++){
            if (arr[j].year< arr[smallestIndex].year)
                smallestIndex = j; 
        }
        date temp= arr[i]; 
        arr[i]= arr[smallestIndex];
        arr[smallestIndex]=temp;
    }

}

int main() {
    date arr[5];
    for(int i=0; i<5; i++){
        cout<<"enter day: ";
        cin>>arr[i].day;
        cout<< "enter month: ";
        cin >>arr[i].month;
        cout<<"enter year: ";
        cin>> arr[i].year; 
    }
    cout << "unsorted array: " << endl;
    for(int i=0; i<5; i++)  arr[i].print();
    selectionSort(arr, 5);
    cout << "sorted array: " << endl;
    for(int i=0; i<5; i++) arr[i].print();
    
}