#include <iostream>
using namespace std;

// function returns index of where the valueToSearch is found in the array
int interpolationSearch(int array[], int sizeOfArray, int valueToSearch) { // can pass high & low as parameters too 
    int low = 0; // lower bound of the search area(in our case the entire array is the search area)
    int high = sizeOfArray - 1; // upper bound

    while (valueToSearch <= array[high] && valueToSearch >= array[low] && low <= high) { // check if the value is within the bounds of the array
        int probe = low + (high - low) * (valueToSearch - array[low]) / (array[high] - array[low]); // learn this formula. we get the estimated position of the value to search, ke iss index ke around wo value mil jayegi 

        if (array[probe] == valueToSearch) {
            return probe;
        }
        else if (array[probe] < valueToSearch) {
            low = probe + 1; // narrowing down the search area, just the way we do in binary search
        }
        else {
            high = probe - 1;
        }
    }
    return -1; // if value not found in the array
}

int main() {
    int arr[] = {1, 5, 7, 9, 12, 15, 18, 20, 25, 30, 34, 40, 45, 50};
    int indexOfVaueToSearch = interpolationSearch(arr, 14, 79);
    if (indexOfVaueToSearch != -1) {
        cout << "found at index: " << indexOfVaueToSearch << endl;
    } else {
        cout << "value not found in the array." << endl;
    }
}