#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        map<int, string, greater<int>> mp;
        for (auto& it : freq) {
            mp[it.second] += it.first;
        }

        string result = "";
        for (auto& it : mp) {
            for (char c : it.second) {
                result += string(it.first, c);
            }
        }

        return result;
    }
};
