// function to solve the problem of finding two odd occurring numbers in an array
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N) {
        long long int xori = 0;
        for(long long int i = 0; i < N; i++) {
            xori = xori ^ Arr[i];
        }

        long long int rightmost = xori & -xori;

        long long int bucket1 = 0, bucket2 = 0;

        for(long long int i = 0; i < N; i++) {
            if((Arr[i] & rightmost) != 0) bucket1 = bucket1 ^ Arr[i];
            else bucket2 = bucket2 ^ Arr[i];
        }
        
        vector<long long int> ans = {bucket1, bucket2};
        sort(ans.begin(), ans.end());
        reverse(ans.begin(), ans.end());
        return ans;
    }
};