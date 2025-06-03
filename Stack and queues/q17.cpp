// implementing previous smaller element using stack
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    vector<int> G;
    stack<int> st;
    for (int i = 0; i < A.size(); i++) {
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }
        if (st.empty()) {
            G.push_back(-1);
        } else {
            G.push_back(st.top());
        }
        st.push(A[i]);
    }
    return G;
}
