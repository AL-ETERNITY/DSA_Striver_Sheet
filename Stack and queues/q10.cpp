// implementation of postfix to infix conversion using stack
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
  public:
    string postToInfix(string exp) {
        int i = 0;
        int n = exp.length();
        stack<string> PTI;

        while(i < n){
            if((exp[i] >= 'A' && exp[i] <= 'Z') || 
               (exp[i] >= 'a' && exp[i] <= 'z') || 
               (exp[i] >= '0' && exp[i] <= '9')){
                // Convert char to string before pushing
                PTI.push(string{exp[i]});
            }
            else {
                // Pop two operands
                string t1 = PTI.top(); PTI.pop();
                string t2 = PTI.top(); PTI.pop();

                // Combine into infix expression
                string con_str = '(' + t2 + exp[i] + t1 + ')';
                PTI.push(con_str);
            }
            i++;
        }

        return PTI.top();
    }
};