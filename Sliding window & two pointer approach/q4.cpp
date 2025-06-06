// function to find the length of the longest substring that can be formed by replacing at most k characters in a given string s.
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxlen = 0;
        int maxfreq = 0;
        unordered_map<char,int> mp;

        for(int right=0;right<s.length();right++){
            mp[s[right]]++;
            maxfreq = max(maxfreq, mp[s[right]]);
            if((right-left+1) - maxfreq > k){
                mp[s[left]]--;
                left++;
            }
            maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
    }
};