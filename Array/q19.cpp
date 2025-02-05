#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
    
    int pairWithMaxSum(vector<int> &arr) {   
       int maxSum=INT_MIN;
       for(int i=1;i<arr.size();i++)
          maxSum = max(maxSum, arr[i-1]+arr[i]);
       return maxSum;
    }