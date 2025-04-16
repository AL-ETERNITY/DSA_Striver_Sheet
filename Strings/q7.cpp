#include<bits/stdc++.h>
using namespace std;

// using 2 array
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int arr1[26] = {0}, arr2[26] = {0};

        for(int i = 0; i < s.length(); i++) {
            arr1[s[i] - 'a']++;
            arr2[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (arr1[i] != arr2[i]) return false;
        }

        return true;
    }
};

// using one array
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        int count[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }
        return true;
    }
};

// if input contains unicode characters
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> count;

        for (int i = 0; i < s.length(); i++) {
            count[s[i]]++;
            count[t[i]]--;
        }

        for (auto& pair : count) {
            if (pair.second != 0) return false;
        }

        return true;
    }
};
    