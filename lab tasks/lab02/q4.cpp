// Task #4:
// Create a dynamic program that manages monthly expenses for a family.
// => Use a 1D dynamic array to store expenses for n months.
// => Add a feature to resize the array if the user wants to track more months later.
// => Compute and display the total and average expenses.

#include <iostream>
using namespace std;

int main (){
    int numOfMonths, userIn;
    float *arr;
    cout << "enter number of months to track expenses: ";
    cin >> numOfMonths;
    arr = new float[numOfMonths];

    for(int i= 0; i <numOfMonths; i++) {
        cout << "enter expense for month " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "do you want to resize array to add more months? enter 0 for no, or enter how many more months u want: ";
    cin >> userIn;
    if (userIn> 0) {
        float *temp = new float[numOfMonths + userIn];
        for (int i = 0; i < numOfMonths; i++){
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        for (int i = numOfMonths; i < numOfMonths + userIn; i++) {
            cout << "enter expense for month " << i+1 << ": ";
            cin >> arr[i];
        }
        numOfMonths += userIn;
    }
    float total = 0, avg;
    for(int i=0; i < numOfMonths; i++) {
        total += arr[i];
    }
    cout << "total expenses: " << total<< endl;
    avg = total / numOfMonths;
    cout <<"average expenses: " << avg << endl;
    delete[] arr;
}