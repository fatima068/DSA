#include <iostream>
using namespace std;

int recursiveLinearSearch(int arr[], int size, int target, int index = 0) {
    // Base case 1: Reached end of array (not found)
    if (index >= size) {
        return -1;
    }
    // Base case 2: Found the target
    if (arr[index] == target) {
        return index;
    }
    
    // Recursive case: Check next element
    return recursiveLinearSearch(arr, size, target, index + 1);
}

int main() {
    int arr[] = {10, 23, 45, 7, 32, 89, 5, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 32;

    int result = recursiveLinearSearch(arr, size, target);

    if (result == -1) {
        cout << "Element not found in the array" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }
}