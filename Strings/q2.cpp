#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string reverseWords(string s) {
            int n = s.length();
            int write = 0;
            bool spaceSeen = false;
    
            for (int read = 0; read < n; read++) {
                if (s[read] != ' ') {
                    s[write++] = s[read];
                    spaceSeen = false;
                } 
                else if (!spaceSeen) {
                    s[write++] = ' ';
                    spaceSeen = true;
                }
            }
    
            if (write > 0 && s[write - 1] == ' ') write--;
    
            int start = 0;
            if (s[0] == ' ') start = 1;
    
            s = s.substr(start, write - start);
    
            reverse(s.begin(), s.end());
            int left = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == ' ') {
                    reverse(s.begin() + left, s.begin() + i);
                    left = i + 1;
                }
            }
            reverse(s.begin() + left, s.end());
            return s;
        }
    };