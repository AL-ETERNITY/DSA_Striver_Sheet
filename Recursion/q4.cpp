// function to solve the problem of sorting a stack using recursion
#include <bits/stdc++.h>
using namespace std;
class SortedStack{
public:
    stack<int> s;
    void sort();
};
void insertSorted(stack<int>& s, int x) {
    if (s.empty() || s.top() <= x) {
        s.push(x);
        return;
    }
    
    int temp = s.top();
    s.pop();
    insertSorted(s, x);
    s.push(temp);
}

void SortedStack::sort() {
    if (s.empty()) return;

    int temp = s.top();
    s.pop();
    sort();
    insertSorted(s, temp);
}