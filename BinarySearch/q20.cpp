#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin(), weights.end());
        int e = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int day = 1;
            int sum = 0;

            for (int i = 0; i < weights.size(); i++) {
                if (sum + weights[i] > mid) {
                    day++;
                    sum = 0;
                }
                sum += weights[i];
            }

            if (day <= days) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};
