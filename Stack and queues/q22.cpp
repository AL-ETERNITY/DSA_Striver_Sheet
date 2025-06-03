// implemented sum subarray ranges problem using stack
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private: 
    vector<int> NSE(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<int> nse(n);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> PSEE(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<int> psee(n);

        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    long long sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans1 = NSE(nums);
        vector<int> ans2 = PSEE(nums);
        long long total = 0;
        for(int i = 0; i < n; i++) {
            int left = i - ans2[i];
            int right = ans1[i] - i;
            total += 1LL * right * left * nums[i];
        }
        return total;
    }

    vector<int> NGE(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<int> nge(n);

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> PGEE(vector<int>& nums){
        int n = nums.size();
        stack<int> st;
        vector<int> pgee(n);

        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            pgee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pgee;
    }

    long long sumSubarrayMax(vector<int>& nums) {
        vector<int> ans1 = NGE(nums);
        vector<int> ans2 = PGEE(nums);

        long long total = 0;
        for (int i = 0; i < nums.size(); i++) {
            int left = i - ans2[i];
            int right = ans1[i] - i;
            total += 1LL * right * left * nums[i];
        }
        return total;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        long long maxSum = sumSubarrayMax(nums);
        long long minSum = sumSubarrayMins(nums);
        return maxSum - minSum;
    }
};
