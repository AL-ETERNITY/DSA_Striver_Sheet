// implement stack using single queue
#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;
public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) return -1;
        int top = q.front();
        q.pop();
        return top;
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};