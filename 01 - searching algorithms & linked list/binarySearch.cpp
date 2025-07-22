#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        // Calculate middle point (prevents overflow compared to (left+right)/2)
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid;  // Target found, return index
        }

        // If target is greater, ignore left half
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }
    return -1; // Target not found in array
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 72;

    int result = binarySearch(arr, size, target);

    if (result == -1) {
        cout << "Element not found in the array" << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }
}