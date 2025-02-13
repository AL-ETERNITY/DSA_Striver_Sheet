#include<bits/stdc++.h>
using namespace std;

int nthRoot(int n, int m) {
    if (m == 0 || m == 1)
        return m;
    
    int s = 1;
    int e = m;
    int ans = -1;
    
    while (s <= e) {
        int mid = s + (e - s) / 2;
        
        if (pow(mid, n) == m) {
            return mid;
        }
        else if (pow(mid, n) > m) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}