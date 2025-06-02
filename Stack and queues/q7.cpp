// valid parentheses
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && ((st.top()=='(' && s[i]==')') || (st.top()=='[' && s[i]==']') || (st.top()=='{' && s[i]=='}'))){
                st.pop();
            } 
            else{
                st.push(s[i]);
            }
        }
        return (st.empty());
    }
};