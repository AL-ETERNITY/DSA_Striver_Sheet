// function to solve the problem of partitioning a string into all possible palindromic substrings.
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool isPalindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    void findpartitions(string s, vector<vector<string>>& ans, vector<string> output, int index){
        if(index == s.length()){
            ans.push_back(output);
            return;
        }

        for(int i = index; i<s.length(); i++){
            if(isPalindrome(s, index, i)){
                output.push_back(s.substr(index, i-index+1));
                findpartitions(s, ans, output, i+1);
                output.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        findpartitions(s, ans, output, 0);
        return ans;
    }
};