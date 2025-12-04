/*Question#4: You are developing a search feature for a large book database. Implement the KMP algorithm to search for a query string in the book’s content. Return all positions where the query occurs. Example:
Input: Text = ababababc 
Pattern = abab
Output: [0, 2, 4]
Extra Challenge: Show the LPS (Longest Prefix Suffix) array used for the search.*/

#include <iostream>
#include <string>
using namespace std;

void computeLPSArray(const string &pattern, int* lps) {
    int m = pattern.length();
    lps[0] = 0; 
    int len = 0,  i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } 
        else {
            if (len != 0) 
                len = lps[len - 1]; 

            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(const string &text, const string &pattern) {
    int n = text.length(), m = pattern.length();
    bool found = false;
    int* lps = new int[m];
    computeLPSArray(pattern, lps);
    cout << "LPS array: ";
    for (int i = 0; i < m; i++) 
        cout << lps[i] << " ";
    cout << endl << "[";

    int i = 0, j = 0; 
    while (i < n) {
        if (pattern[j] == text[i]) 
            i++; j++;

        if (j == m) {
            cout << i - j << ",";
            found = true;
            j = lps[j - 1]; 
        } 
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0) 
                j = lps[j - 1]; 
            else 
                i++; 
        }
    }

    if (found) cout << "\b]";
    else cout << "\bnot found"; 
}

int main() {
    string text = "abababababc";
    string pattern = "abab";
    KMPSearch(text, pattern);
}
