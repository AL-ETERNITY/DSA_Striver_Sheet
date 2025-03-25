#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int duplicate = -1, missing = -1;

        for (int i = 0; i < n; i++) {
            int index = abs(arr[i]) - 1;
            if (index >= n) continue;

            if (arr[index] < 0) {
                duplicate = abs(arr[i]);
            } else {
                arr[index] = -arr[index]; 
            }
        }
        
        long long sumN = (1LL * n * (n + 1)) / 2;
        long long sumArr = 0;
        for (int i = 0; i < n; i++) {
            sumArr += abs(arr[i]);
        }
        missing = sumN - (sumArr - duplicate);

        return {duplicate, missing};
    }
};