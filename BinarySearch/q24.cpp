#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &boards, int k, int mid) 
{
    int painterCount = 1;
    int timeSum = 0;
    
    for(int i = 0; i<boards.size(); i++) 
    {
        if(timeSum + boards[i] <= mid) 
        {
            timeSum += boards[i];
        }
        else
        {
            painterCount++;
            if(painterCount > k || boards[i] > mid ) 
            {
              return false;
            }
            timeSum = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = *max_element(boards.begin(), boards.end());
    int e = accumulate(boards.begin(), boards.end(), 0);
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e)
    {
        if(isPossible(boards,k,mid)) 
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
