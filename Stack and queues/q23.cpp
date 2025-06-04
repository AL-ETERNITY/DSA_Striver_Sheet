// implemented removeKdigits problem using stack
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i = 0;i<num.length();i++){
            while(!st.empty() && k>0 && (st.top() - '0' > num[i] - '0')){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }

        if(st.empty()) return "0";
        
        else{

            string res = "";
            while (!st.empty()) {
                res.push_back(st.top());
                st.pop();
            }

            while(res.size() != 0 && res.back() == '0'){
                res.pop_back();
            }
            reverse(res.begin(),res.end());

            if(res.empty()) return "0";

            else return res;
        }
    }
};