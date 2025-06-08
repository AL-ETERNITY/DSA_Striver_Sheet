// function to check if a string is a valid parentheses string with '*' as a wildcard
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0;
        int maxi = 0;
        for(char c : s) {
            if (c == '(') {
                mini++;
                maxi++;
            } else if (c == ')') {
                if (mini > 0) mini--;
                maxi--;
                if (maxi < 0) return false;
            } else { // c == '*'
                if (mini > 0) mini--;
                maxi++;
            }
        }
        return mini == 0;
    }
};