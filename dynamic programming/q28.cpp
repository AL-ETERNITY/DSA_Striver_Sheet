// function to solve the problem of finding the longest palindromic subsequence in a string
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[m];
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return longestCommonSubsequence(s, s2);
    }
public:
    int minInsertions(string s) {
        int n = s.length();
        int lps = longestPalindromeSubseq(s);
        return n-lps;
    }
};