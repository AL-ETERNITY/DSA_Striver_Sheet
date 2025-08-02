// implementation of infix to prefix conversion using stack
#include <bits/stdc++.h>
using namespace std;

class Solution{
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
        string infixToPrefix(string s){
            stack<char> st;
            int i = 0;
            int n = s.length();
            string ans = "";

            // Reverse the string
            reverse(s.begin(), s.end());

            // Replace '(' with ')' and vice versa
            for (int j = 0; j < n; j++) {
                if (s[j] == '(') {
                    s[j] = ')';
                } 
                else if (s[j] == ')') {
                    s[j] = '(';
                }
            }

            // Infix to Postfix Conversion
            while(i<n){
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
                    if(!st.empty()) st.pop();
                }
                else{
                    if(s[i] == '^'){
                        while(!st.empty() && (priority(st.top()) >= priority(s[i]))){
                            ans += st.top();
                            st.pop();
                        }
                    }
                    else{
                        while(!st.empty() && (priority(st.top()) > priority(s[i]))){
                            ans += st.top();
                            st.pop();
                        }
                    }
                    st.push(s[i]);
                }
                i++;
            }

            // Pop all remaining operators from the stack
            while(!st.empty()){
                ans += st.top();
                st.pop();
            }

            // Reverse the result to get the prefix expression
            reverse(ans.begin(), ans.end());
            return ans;
        }
};