// impelemantation of infix to postfix conversion using stack
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
  private:
    int priority(char ch){
        if(ch == '^'){
            return 3;
        }
        else if((ch == '*') || (ch == '/')){
            return 2;
        }
        else if((ch == '+') || (ch == '-')){
            return 1;
        }
        else {
            return 0;
        }
    }
  public:
    string infixToPostfix(string& s) {
        stack<char> st;
        string ans = "";
        int i = 0;
        int n = s.length();
        while(i < n){
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')){
                ans += s[i];
            }
            else if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && (priority(st.top()) >= priority(s[i]))){
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};