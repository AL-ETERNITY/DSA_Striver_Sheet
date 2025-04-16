#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int count_isOpen = 0;
        int maxi = 0;
        bool found = false;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                count_isOpen++;
                found = true;
            }
            else if(s[i] == ')'){
                count_isOpen--;
                maxi = max(maxi, count_isOpen);
            }
        }
        if(found == false) return 0;
        else return maxi+1;
    }
};