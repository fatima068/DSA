#include <iostream>
#include <string>
using namespace std;

int interpolationSearchRecursive(int arr[], int element, int low, int high) {
    // Calculate the probable position using interpolation formula
    int pos = low + ((double)(high - low) * (element - arr[low])) / (arr[high] - arr[low]);

    // Check if the calculated position is within bounds
    if (pos <= high && pos >= low) {
        // If element is found at the calculated position
        if (element == arr[pos]) {
            return pos;
        }
        // If element is smaller, search in the left subarray
        else if (element < arr[pos]) {
            return interpolationSearchRecursive(arr, element, low, pos - 1);
        }
        // If element is larger, search in the right subarray
        else if (element > arr[pos]) {
            return interpolationSearchRecursive(arr, element, pos + 1, high);
        }
    }

    // If element is not found in the array
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