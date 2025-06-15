// function to solve the problem of finding the longest prefix which is also a suffix in a given string
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> computeLPSArray(string s) {
        int m = s.length();
        vector<int> LPS(m, 0);
        int len = 0;
        int i = 1;
        while (i < m) {
            if (s[i] == s[len]) {
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
public:
    string longestPrefix(string s) {
        vector<int> lps = computeLPSArray(s);
        int len = lps[s.length() - 1];
        return s.substr(0, len);
    }
};