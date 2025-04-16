#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int output = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i] == 'I'){
                if((i+1 < n) && s[i+1] == 'V'){
                    output += 4;
                    i++;
                }
                else if((i+1 < n) && s[i+1] == 'X'){
                    output += 9;
                    i++;
                }
                else{
                    output += 1;
                } 
            }
            else if(s[i] == 'V'){
                output += 5;
            }
            else if(s[i] == 'X'){
                if((i+1 < n) && s[i+1] == 'L'){
                    output += 40;
                    i++;
                }
                else if((i+1 < n) && s[i+1] == 'C'){
                    output += 90;
                    i++;
                }
                else{
                    output += 10;
                } 
            }
            else if(s[i] == 'L'){
                output += 50;
            }
            else if(s[i] == 'C'){
                if((i+1 < n) && s[i+1] == 'D'){
                    output += 400;
                    i++;
                }
                else if((i+1 < n) && s[i+1] == 'M'){
                    output += 900;
                    i++;
                }
                else{
                    output += 100;
                } 
            }
            else if(s[i] == 'D'){
                output += 500;
            }
            else if(s[i] == 'M'){
                output += 1000;
            }
        }
        return output;
    }
};