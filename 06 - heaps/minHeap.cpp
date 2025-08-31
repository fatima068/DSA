#include <iostream>
#include <math.h>
#include <climits>
using namespace std;

class MinHeap {
    public:
    int *arr;
    int capacity;
    int currentSize;

    MinHeap(int capacity) : capacity(capacity), currentSize(0) {
        arr = new int[capacity];
    }

    void deleteKey(int index) {
        decreaseKey(index);
        extractMin();
    }

    void decreaseKey(int index) {
        arr[index] = INT_MIN;
        while (index != 0 && arr[getParentIndex(index)] > arr[index]) {
            int temp = arr[getParentIndex(index)];
            arr[getParentIndex(index)] = arr[index];
            arr[index] = temp;
            index = getParentIndex(index);
        }
    }

    void insertKey(int val) {
        if (currentSize == capacity) {
            cout << "heap full" << endl;
            return;
        }
        int i = currentSize;
        currentSize++;
        arr[i] = val;
        while (i != 0 && arr[getParentIndex(i)] > arr[i]) { //swapping condition
            int temp = arr[getParentIndex(i)];
            arr[getParentIndex(i)] = arr[i];
            arr[i] = temp;
            i = getParentIndex(i);
        }
    }

    int extractMin() {
        if (currentSize <= 0) {
            cout << "heap empty\n";
            return INT_MAX;
        }
        if (currentSize == 1) {
            currentSize--;
            return arr[0];
        }
        int root = arr[0];
        arr[0] = arr[currentSize-1];
        currentSize--;
        heapify(0);
        return root;
    }

    void heapify(int i) {
        int rightIndex = getRightIndex(i);
        int leftIndex = getLeftIndex(i);
        int smallestIndex = i;
        if (leftIndex < currentSize && arr[leftIndex] < arr[smallestIndex]) {
            smallestIndex = leftIndex;
            if (rightIndex < currentSize && arr[rightIndex] < arr[smallestIndex]) {
                smallestIndex = rightIndex;
            }
        }
        if (smallestIndex != i) {
            int temp = arr[i];
            arr[i] = arr[smallestIndex];
            arr[smallestIndex] = temp;
            heapify(smallestIndex);
        }
    }

    int getParentIndex(int i) {
        return (i-1)/2;
    }

    int getLeftIndex(int i) {
        return 2*i+1;
    }

    int getRightIndex(int i) {
        return 2*i+2;
    }

    int getHeapHeight() {
        return ceil(log2(currentSize+1)) - 1;
    }

    void linearSearch(int val) {
        for (int i = 0; i < currentSize; i++) {
            if (arr[i] == val) {
                cout << val << " found at index " << i << endl;
                return;
            }
        }
        cout << val << " not found" << endl;
    }

    void printArray() {
        for (int i = 0; i <currentSize; i++) {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap heap(6);
    heap.insertKey(5);
    heap.insertKey(4);
    heap.insertKey(8);
    heap.insertKey(9);
    heap.insertKey(3);
    heap.insertKey(1);
    heap.printArray();
    heap.deleteKey(2);
    heap.printArray();

}