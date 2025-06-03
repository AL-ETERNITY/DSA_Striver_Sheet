// implemented asteroid collision problem using stack
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();

        for (int a : asteroids) {
            bool alive = true;

            while (!st.empty() && a < 0 && st.top() > 0) {
                if (abs(a) > st.top()) {
                    st.pop();
                } else if (abs(a) == st.top()) {
                    st.pop();
                    alive = false;
                    break;
                } else {
                    alive = false;
                    break;
                }
            }

            if (alive) st.push(a);
        }

        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};