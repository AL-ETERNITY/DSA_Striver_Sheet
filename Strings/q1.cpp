#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        string removeOuterParentheses(string s) {
            int n = s.length();
            int count_isOpen = 0;
            int count_isClosed = 0;
            string output = "";
            for (int i = 0; i < n; i++) {
                if (s[i] == '(' && count_isOpen == 0) {
                    count_isOpen++;
                }
                else if (s[i] == '(') {
                    count_isOpen++;
                    output += s[i];
                }
                else if (s[i] == ')') { 
                    count_isClosed++;
                    if (count_isOpen == count_isClosed) {
                        count_isOpen = 0;
                        count_isClosed = 0;
                    }
                    else {
                        output += s[i];
                    }
                }
            }
            return output;
        }
    };
    