#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int s = 1;
        int e = *max_element(piles.begin(), piles.end()); 
        int result = e;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int hours = 0;

            for (int i = 0; i < n; i++) {
                hours += (piles[i] + mid - 1) / mid;
                if(hours > h)
                {
                    break;
                }
            }

            if (hours <= h) {
                result = mid;
                e = mid - 1; 
            } 
            else {
                s = mid + 1; 
            }
        }

        return result;
    }
};