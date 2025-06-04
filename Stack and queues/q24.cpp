// implemented largest rectangle in histogram problem using stack
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> NSE(vector<int> arr){
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();

            st.push(i); 
        }
        return nse;
    }

    vector<int> PSE(vector<int> arr){
        int n = arr.size();
        stack<int> st;
        vector<int> pse(n);
        for(int i = 0;i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();

            st.push(i);
        }
        return pse;    
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        
        vector<int> next = NSE(heights);
        vector<int> prev = PSE(heights);

        int area = INT_MIN;
        for(int i=0; i<n; i++) {
            int l = heights[i];
            int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
};