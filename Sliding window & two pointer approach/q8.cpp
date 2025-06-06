// function to solve the problem of finding the longest substring with exactly k distinct characters
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char,int> freq;
        int maxlen = 0;
        int left = 0;
        for(int right=0;right<s.length();right++){
            freq[s[right]]++;
            while(freq.size() > k){
                freq[s[left]]--;
                if(freq[s[left]] == 0){
                    freq.erase(s[left]);
                }
                left++;
            }
            maxlen = max(maxlen, right-left+1);
        }
        if(freq.size() != k){
            return -1;
        }
        else{
            return maxlen;
        }
    }
};