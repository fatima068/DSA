#include <iostream>
#include <string>
using namespace std;

#define BASE 256

void rabinKarp(string text, string pattern, int primeMod) {
    int textLen = text.length();
    int patternLen = pattern.length();

    if (patternLen == 0 || patternLen > textLen) {
        cout << "No valid pattern to search.\n";
        return;
    }

    int patternHash = 0;
    int windowHash = 0;       
    int highestPower = 1;
    for (int i = 0; i < patternLen - 1; i++) {
        highestPower = (highestPower * BASE) % primeMod;
    }
    for (int i = 0; i < patternLen; i++) {
        patternHash = (BASE * patternHash + pattern[i]) % primeMod;
        windowHash = (BASE * windowHash + text[i]) % primeMod;
    }

    for (int i = 0; i <= textLen - patternLen; i++) {
        if (patternHash == windowHash) {
            bool isMatch = true;

            for (int j = 0; j < patternLen; j++) {
                if (text[i + j] != pattern[j]) {
                    isMatch = false;
                    break;
                }
            }

            if (isMatch) {
                cout << "Pattern found at index " << i << endl;
            }
        }
        if (i < textLen - patternLen) {
            windowHash = (BASE*(windowHash - text[i] * highestPower) + text[i + patternLen]) % primeMod;
            if (windowHash < 0)
                windowHash += primeMod;
        }
    }
}

int main() {
    string text = "ABAAABCDBBABCDDEBCABC";
    string pattern = "ABC";

    int primeMod = 101;

    rabinKarp(text, pattern, primeMod);
}
