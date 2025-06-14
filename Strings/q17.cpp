// problem to solve: Find the first occurrence of a pattern in a text string.
#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time Complexity: O(n * m), where n is the length of the text and m is the length of the pattern.
// Space Complexity: O(1), since we are not using any extra space that grows with input size.
class Solution {
  public:
    int findMatching(string text, string pat) {
        int n = text.length(), m = pat.length();
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && text[i + j] == pat[j]) {
                j++;
            }
            if (j == m) {
                return i;
            }
        }
        return -1;
    }
};

// KMP Algorithm
// Time Complexity: O(n + m), where n is the length of the text and m is the length of the pattern.
// Space Complexity: O(m) for the LPS array.
class Solution{
    public:
    vector<int> computeLPSArray(string pat) {
        int m = pat.length();
        vector<int> lps(m, 0);
        int len = 0; // length of the previous longest prefix suffix
        int i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } 
            else {
                if (len != 0) {
                    len = lps[len - 1];
                } 
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    int findMatching(string text, string pat) {
        int n = text.length(), m = pat.length();
        vector<int> lps = computeLPSArray(pat);
        int i = 0, j = 0; // i for text, j for pattern
        while (i < n) {
            if (pat[j] == text[i]) {
                i++;
                j++;
            }
            if (j == m) {
                return i - j; // Match found, return starting index
            }
            else if (i < n && pat[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1]; // Use LPS to skip characters
                } else {
                    i++; // Move to the next character in text
                }
            }
        }
        return -1; // No match found
    }
};
