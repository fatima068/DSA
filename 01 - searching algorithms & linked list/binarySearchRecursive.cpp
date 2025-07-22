#include <iostream>
using namespace std;

int binarySearch(int arr[], int target, int left, int right) {
    // Base case: element not found
    if (left > right) {
        return -1;
    }

    // Calculate middle index (prevents overflow)
    int mid = left + (right - left) / 2;

    // If element is found at mid
    if (arr[mid] == target) {
        return mid;
    }
    // If element is in left half
    else if (arr[mid] > target) {
        return binarySearch(arr, target, left, mid - 1);
    }
    // If element is in right half
    else {
        return binarySearch(arr, target, mid + 1, right);
    }
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearch(arr, target, 0, size - 1);

    if (result == -1) {
        cout << "Element not found in the array" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }
}