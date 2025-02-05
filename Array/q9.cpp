#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        vector<int> arr;
        int n = a.size();
        int m = b.size();
        int i = 0, j = 0;
    
        while (i < n && j < m) {
            if (a[i] < b[j]) {
                arr.push_back(a[i]);
                i++;
            } else if (a[i] == b[j]) {
                arr.push_back(a[i]);
                i++;
                j++;
            } else {
                arr.push_back(b[j]);
                j++;
            }
        }
    
        while (i < n) {
            arr.push_back(a[i]);
            i++;
        }
    
        while (j < m) {
            arr.push_back(b[j]);
            j++;
        }
    
        int uniqueIndex = 0;
        for (int k = 1; k < arr.size(); k++) {
            if (arr[k] != arr[uniqueIndex]) {
                uniqueIndex++;
                arr[uniqueIndex] = arr[k];
            }
        }
    
        arr.erase(arr.begin() + uniqueIndex + 1, arr.end());
    
        return arr;
    }