// function to solve the problem of reversing a stack using recursion
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void insertAtBottom(stack<int> &St, int x) {
        if (St.empty()) {
            St.push(x);
            return;
        }
        
        int temp = St.top();
        St.pop();
        insertAtBottom(St, x);
        St.push(temp);
    }

    void Reverse(stack<int> &St) {
        if (St.empty()) return;

        int temp = St.top();
        St.pop();
        Reverse(St);
        insertAtBottom(St, temp);
    }
};
