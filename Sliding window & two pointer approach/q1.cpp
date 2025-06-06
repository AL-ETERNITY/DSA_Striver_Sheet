// Function to find the length of the longest substring without repeating characters
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            char current = s[right];
            freq[current]++;
            
            while (freq[current] > 1) {
                freq[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
