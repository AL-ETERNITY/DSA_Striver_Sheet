#include<bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
    if (n == 0 || n == 1)
        return n;
    
    int s = 1;
    int e = n;
    int ans = -1;
    
    while(s<=e){
        int mid = s + (e-s)/2;
        if(mid*mid == n){
            return mid;
        }
        else if(mid*mid > n){
            e = mid - 1;
        }
        else{
            ans = mid;
            s = mid + 1;
        }
    }
    return ans;
}