// Create a dynamic program to store temperature readings of a city for n days and m different times in a day
// using a 2D array.
// => Calculate the daily average temperature.
// => Find the hottest and coldest day.
#include <iostream>
using namespace std;

void printArray(float **arr, int n, int *m){
    for (int i=0; i < n; i++){
        for(int j =0; j<m[i];j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    cout << "every row represents a day and column represents readings in that day" << endl;
    int n;
    int *m;
    float **arr;
    cout << "number of days: ";
    cin >> n;
    m = new int[n];
    for (int i =0; i < n; i++){
        cout << "number of readings in day " << i+1 << ": ";
        cin >> m[i];
    }    
    arr = new float*[n];
    for (int i=0; i < n; i++){
        arr[i] = new float[m[i]];
    } // jagged 2d array has been created here and also stored num of days in var n and num of readings in each day in *m array
    //now we take input for the array
    for (int i=0; i < n; i++){
        for(int j =0; j<m[i];j++) {
            cout << " reading " << j+1 << " of day " << i+1 << ": ";
            cin >> arr[i][j];
        }
    }
    cout << "temperature array: \n";
    printArray(arr, n, m);
    //daily avg temp and hottest and coldest day calculated here:
    float total = 0, avg, hottestAvg = 0, coldestAvg = 1000;
    int hotDayNum, coldDayNum;
    for(int i = 0 ; i<n; i++) {
        total = 0;
        for (int j = 0; j <m[i]; j++) {
            total += arr[i][j];
        }
        avg = total/m[i];
        cout << "average temperature of day " << i+1 << " is: " << avg<< endl;
        if (avg > hottestAvg){
            hotDayNum = i;
            hottestAvg = avg;
        }
        if(avg < coldestAvg) {
            coldestAvg = avg;
            coldDayNum = i;
        }
    }
    cout << "hottest day: day " << hotDayNum+1 << endl;
    cout << "coldest day: day " << coldDayNum+1 << endl;
    delete[] m;
    for (int i =0; i<n; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}