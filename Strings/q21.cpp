# include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> computeLPSArray(string str) {
        int m = str.length();
        vector<int> LPS(m, 0);
        int len = 0;
        int i = 1;
        while (i < m) {
            if (str[i] == str[len]) {
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
    string shortestPalindrome(string s) {
        if(s == "") return "";

        string rev = s;
        reverse(rev.begin(), rev.end());
        string str = s + '#' + rev;

        vector<int> lps = computeLPSArray(str);

        int len = lps[str.length() - 1];

        string toAdd = "";
        if(len < s.length()) {
            toAdd = s.substr(len);
            reverse(toAdd.begin(), toAdd.end());
        }

        return toAdd + s;
    }
};