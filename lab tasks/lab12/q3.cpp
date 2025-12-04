/*Question#3: You are designing a DNA sequence analyzer. Implement the Boyer-
Moore algorithm to efficiently find a short DNA motif (pattern) in a long DNA strand.
Return all starting positions of the motif in the strand. Example:
Input: DNA = ACGTACGTGACG
Pattern = ACG
Output: [0, 4, 9]
Extra Challenge: Implement both the bad character and good suffix heuristics for
optimal performance.*/

#include <iostream>
#include <string>
using namespace std;
#define d 256

void badCharHeuristic(string &pattern, int* badChar) {
    int m = pattern.length();
    for (int i = 0; i < d; i++)
        badChar[i] = -1; 
    for (int i = 0; i < m; i++)
        badChar[(int)pattern[i]] = i;
}

void boyerMooreSearch(string &text, string &pattern) {
    int n = text.length();
    int m = pattern.length();
    bool found = false;

    cout << "[";
    int* badChar = new int[d];
    badCharHeuristic(pattern, badChar);
    int s = 0; 
    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) 
            j--;
        if (j < 0) {
            cout << s << ",";
            found = true;
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        } 
        else {
            int shift = max(1, j - badChar[text[s + j]]);
            s += shift;
        }
    }

    if (found) cout << "\b]" << endl;
    else cout << "\bnot found" << endl;
}

int main() {
    string text = "ACGTACGTGACG";
    string pattern = "ACG";
    boyerMooreSearch(text, pattern);
}