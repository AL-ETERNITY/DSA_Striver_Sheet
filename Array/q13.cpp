#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumMap; // To store prefix sums and their indices
        int sum = 0;
        int maxLength = 0;
    
        // Initialize the prefix sum map
        prefixSumMap[0] = -1;
    
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
    
            // Check if there is a prefix sum that makes the subarray sum equal to k
            if (prefixSumMap.find(sum - k) != prefixSumMap.end()) {
                maxLength = max(maxLength, i - prefixSumMap[sum - k]);
            }
    
            // Store the prefix sum in the map if it doesn't already exist
            if (prefixSumMap.find(sum) == prefixSumMap.end()) {
                prefixSumMap[sum] = i;
            }
        }
    
        return maxLength;
    }