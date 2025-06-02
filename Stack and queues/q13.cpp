// implementation of post to prefix conversion using stack
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
  public:
    string postToPre(string post_exp) {
        int i = 0;
        int n = post_exp.length();
        stack<string> st;
        while(i<n){
           if((post_exp[i]>='A' && post_exp[i]<='Z') || (post_exp[i]>='a' && post_exp[i]<='z') || (post_exp[i]>='0' && post_exp[i]<='9')){
               st.push(string{post_exp[i]});
            }
            else{
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                string con_str = post_exp[i] + t2 + t1;
                st.push(con_str);
            }
            i++;
        }
        return st.top();
    }
};