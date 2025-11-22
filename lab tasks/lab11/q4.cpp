/* Given an array of distinct integers, find using hashing if there are two pairs (a, b) and (c, d) such that a+b = c+d, and a, b, c, and d are distinct elements. If there are multiple answers, then print any of them.
Input: {3, 4, 7, 1, 2, 9, 8}
Output: (3, 8) and (4, 7)
Explanation: 3+8 = 4+7
Input: {3, 4, 7, 1, 12, 9};
Output: (4, 12) and (7, 9)
Explanation: 4+12 = 7+9
Input: {65, 30, 7, 90, 1, 9, 8};
Output: No pairs found */
#include <iostream>
using namespace std;

void makePairs(int numbers[],int size) {
    int maxSums = 1000;
    int first[maxSums] = {0};
    int second[maxSums] = {0};
    bool sumStored[maxSums] = {false};
    
    for (int firstIndex = 0; firstIndex < size; firstIndex++) {
        for (int secondIndex = firstIndex + 1; secondIndex < size; secondIndex++) {
            int currentSum = numbers[firstIndex] + numbers[secondIndex];
            if (sumStored[currentSum]) {
                int storedFirst = first[currentSum];
                int storedSecond = second[currentSum];
                bool allDifferent = (storedFirst != numbers[firstIndex]) && (storedFirst != numbers[secondIndex]) && (storedSecond != numbers[firstIndex]) && (storedSecond != numbers[secondIndex]);
                
                if (allDifferent ==true) {
                    cout << "(" << storedFirst << ", " << storedSecond << "), ("<< numbers[firstIndex] << ", " << numbers[secondIndex] << ")" <<endl;
                    return;
                }
            } 
            else{
                first[currentSum] =numbers[firstIndex];
                second[currentSum]= numbers[secondIndex];
                sumStored[currentSum] = true;
            }
        }
    }
    cout << "no pairs found" << endl;
}

int main() { 
    int arr[] = {3, 4, 7, 1, 12, 9, 10, 6};
    makePairs(arr, 8);
}
