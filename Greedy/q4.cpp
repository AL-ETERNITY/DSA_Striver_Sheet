// fucntion to solve the problem of Lemonade Change
#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mp;
        for(int i = 0;i<bills.size();i++){
            if(bills[i] == 5){
                mp[5]++;
            }
            else if(bills[i] == 10){
                if(mp[5] < 1){
                    return false;
                }
                else{
                    mp[5]--;
                    mp[10]++;
                }
            }
            else{
                if(mp[5] >=1 && mp[10]>=1){
                    mp[5]--;
                    mp[10]--;
                    mp[20]++;
                }
                else if(mp[5] >= 3){
                    mp[5] -= 3;
                    mp[20]++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};