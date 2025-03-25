#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int maxLen(vector<int>& arr) {
    unordered_map<int, int> prefixSumMap; // To store prefix sums and their indices
    int sum = 0;
    int maxLength = 0;

    // Initialize the prefix sum map
    prefixSumMap[0] = -1;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // Check if there is a prefix sum that makes the subarray sum equal to 0
        if (prefixSumMap.find(sum - 0) != prefixSumMap.end()) {
            maxLength = max(maxLength, i - prefixSumMap[sum - 0]);
        }

        // Store the prefix sum in the map if it doesn't already exist
        if (prefixSumMap.find(sum) == prefixSumMap.end()) {
            prefixSumMap[sum] = i;
        }
    }

    return maxLength;
}
};