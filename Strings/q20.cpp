// function to solve the problem of finding the first occurrence of a substring in a string using the KMP algorithm.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> computeLPSArray(string needle) {
        int m = needle.length();
        vector<int> LPS(m, 0);
        int len = 0;
        int i = 1;
        while (i < m) {
            if (needle[i] == needle[len]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = LPS[len - 1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
        return LPS;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        vector<int> lps = computeLPSArray(needle);

        int i = 0;
        int j = 0;
        
        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if (j == m) {
                return i - j;
            } else if (i < n && haystack[i] != needle[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return -1;
    }
};
