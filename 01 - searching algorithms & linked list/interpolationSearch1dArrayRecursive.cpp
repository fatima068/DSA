#include <iostream>
#include <string>
using namespace std;

int interpolationSearchRecursive(int arr[], int valueToSearch, int low, int high) {
    // Calculate the probable position using interpolation formula
    int pos = low + (high - low) * (valueToSearch - arr[low]) / (arr[high] - arr[low]);

    // Check if the calculated position is within bounds
    if (pos <= high && pos >= low) {
        // If valueToSearch is found at the calculated position
        if (valueToSearch == arr[pos]) {
            return pos;
        }
        // If valueToSearch is smaller, search in the left subarray
        else if (valueToSearch < arr[pos]) {
            return interpolationSearchRecursive(arr, valueToSearch, low, pos - 1);
        }
        // If valueToSearch is larger, search in the right subarray
        else if (valueToSearch > arr[pos]) {
            return interpolationSearchRecursive(arr, valueToSearch, pos + 1, high);
        }
    }

    // If valueToSearch is not found in the array
    return -1;
}

int main() {
    int arr[] = {-213, 10, 43, 49, 54, 100, 345, 546, 765, 1000, 5400};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 100;

    int result = interpolationSearchRecursive(arr, target, 0, size - 1);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
}