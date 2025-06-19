// function to find the k most frequent elements in an array
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
private:
    static bool compare(pair<int,int>& a, pair<int,int>& b){
        return a.second < b.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        for(int num : nums){
            cnt[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(&compare)> pq(&compare);

        for(auto& entry : cnt){
            pq.push({entry.first,entry.second});
        }

        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};