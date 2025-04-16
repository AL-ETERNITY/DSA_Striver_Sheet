#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_length = INT_MAX;
        int index = 0;
        for(int i = 0; i<strs.size(); i++){
            if(strs[i].length() < min_length){
                index = i;
            }
            min_length = min(min_length, (int)strs[i].length());
        }
        string output = "";
        for(int i=0; i<min_length; i++){
            bool common = true;
            for(int j = 0; j<strs.size(); j++){
                if(strs[j][i] != strs[index][i]){
                    common = false;
                    return output;
                }
            }
            if(common == true){
                output += strs[index][i];
            }
        }
        return output;   
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans="";
        sort(v.begin(),v.end());
        int n=v.size();
        string first=v[0],last=v[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;
    }
};