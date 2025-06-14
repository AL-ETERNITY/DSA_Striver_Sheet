// Problem: Given a string s containing only the characters '(' and ')', return the minimum number of parentheses we must add to make the input string valid.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, unmatchedClose = 0;
        for(char c : s) {
            if(c == '(') {
                open++;
            } 
            else { // c == ')'
                if(open > 0) {
                    open--;
                } 
                else {
                    unmatchedClose++;
                }
            }
        }
        return open + unmatchedClose;
    }
};
