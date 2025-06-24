// function to solve the problem of finding the better string
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
        unordered_map<char,int> lastpos;
        unordered_map<int,int> memo;
        
        int count(int i, const string& s){
            if(i<0) return 1;
            
            if(memo.count(i)) return memo[i];
            
            int ans = 2*count(i-1,s);
            
            char ch = s[i];
            if(lastpos.count(ch)){
                ans -= count(lastpos[ch] - 1, s);
            }
            
            lastpos[ch] = i;
            
            return memo[i] = ans;
        }
        
  public:
    string betterString(string &s1, string &s2) {
        memo.clear(); lastpos.clear();
        int cnt1 = count(s1.size() - 1, s1);
        
        memo.clear(); lastpos.clear();
        int cnt2 = count(s2.size() - 1, s2);
        
        return (cnt1 >= cnt2)? s1 : s2;
        
    }
};