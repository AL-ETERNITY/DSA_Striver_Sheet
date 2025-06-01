// implementation of a queue using a =stack
#include <iostream>
#include <stack>
using namespace std;

// method 1: using two stacks but lot of time in push operation, so this would work when we have less push operations
class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {}
    
    void push(int x) {
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        if(s1.empty()) return -1;
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

// method 2: using two stacks but lot of time in pop and top operation , so this would work when we have more push operations
class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {}
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int ans = s2.top();
        s2.pop();
        return ans;
    }
    
    int peek() {
        if (s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s2.empty() && s1.empty();
    }
};