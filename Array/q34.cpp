#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    int currXOR = 0;
    map<int,int> mp;
    mp[currXOR]++;
    int cnt = 0;
    for(int i=0;i<arr.size();i++){
        currXOR ^= arr[i];
        int k = currXOR^x;
        cnt += mp[k];
        mp[currXOR]++;
    }
    return cnt;
}
