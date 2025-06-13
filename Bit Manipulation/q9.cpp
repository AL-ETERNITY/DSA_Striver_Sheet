// function to solve the problem of counting the number of bit flips required to convert an integer 'start' to 'goal'.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start^goal;
        int count = 0;
        while(ans!=0){
            if(ans&1){
                count++;
            }
            ans=ans>>1;
        }
        return count;
    }
};