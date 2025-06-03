// implemented subarray minimums sum problem using stack
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private: 
    vector<int> NSE(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = n;
            }
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }

    vector<int> PSEE(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> psee(n);

        for(int i = 0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(st.empty()){
                psee[i] = -1;
            }
            else{
                psee[i] = st.top();
            }
            st.push(i);
        }
        return psee;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans1 = NSE(arr);
        vector<int> ans2 = PSEE(arr);
        int total = 0;
        int MOD = int(1e9 + 7);
        for(int i = 0; i < n; i++) {
            int left = i - ans2[i];
            int right = ans1[i] - i;
            total = (total + ((1LL * right * left * arr[i]) % MOD)) % MOD;
        }
        return total;
    }
};