// function to find the maximum number of elements in an array that can be formed by taking at most two distinct elements.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int maxlen = 0;
        int left = 0;
        unordered_map<int,int> mp;
        
        for(int right=0; right<arr.size(); right++){
            mp[arr[right]]++;
            while(mp.size() > 2){
                mp[arr[left]]--;
                if(mp[arr[left]] == 0){
                    mp.erase(arr[left]);
                }
                left++;
            }
            maxlen = max(maxlen,right-left+1);
        }
        return maxlen;
    }
};