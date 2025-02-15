#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n) {
            return -1;
        }

        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int cnt = 0;
            int number = 0; 

            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= mid) {
                    cnt++;
                } else {
                    if (cnt >= k) {
                        number += cnt / k;
                    }
                    cnt = 0; 
                }
            }

            if (cnt >= k) { 
                number += cnt / k;
            }

            if (number >= m) {
                e = mid - 1; 
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
};
