/*Question#1: You are developing a text editor. Implement a function that searches for all occurrences of a user-provided keyword in a large document. Use the Brute Force algorithm to find and return the starting indices of the keyword in the document. Example:
Input: Text = the quick brown fox jumps over the lazy dog
Pattern = the;
Output: [0, 31]
Extra Challenge: Count and return the total number of comparisons your algorithm makes.*/ 
#include <iostream>
#include <string> 
using namespace std;
void bruteForceSearch(string text, string pattern, int &comparisions) {
    int n = text.length();
    int m = pattern.length();
    cout << "[";
    bool found = false;
    for (int i = 0; i <= n - m; i++) {
        int j =0;
        while (j < m && text[i + j] == pattern[j]) {
            comparisions++;
            j++;
        }   
        if (j == m) { 
            comparisions++;
            cout << i << ",";
            found = true;
        }
    }
    if (found) { cout << "]" << endl; }
    
    if (found == false) {
        cout << "not found" << endl; 
    }
}
int main() {
    string text ="the quick brown fox jumps over the lazy dog";
    string pattern = "the";
    int comparisions =0;
    bruteForceSearch(text, pattern, comparisions);
    cout << "total comparisions: " << comparisions << endl;
}
