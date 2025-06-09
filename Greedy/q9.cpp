// solution to find the minimum number of platforms required for a railway station so that no train waits
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int n = arr.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        int maxcount = 0;
        while(i<n){
            if(arr[i] <= dep[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            maxcount = max(maxcount, cnt);
        }
        return maxcount;
    }
};