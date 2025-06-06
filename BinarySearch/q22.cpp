#include <bits/stdc++.h>
using namespace std;


bool isPossible(vector<int>& arr, int n, int m, int mid) {

    int studentCount = 1;

    int pageSum = 0;

 

    for (int i = 0; i < n; i++) {

        if (pageSum + arr[i] <= mid) {

            pageSum += arr[i];

        } else {

            studentCount++;

            if (studentCount > m || arr[i] > mid) {

                return false;

            }

            pageSum = arr[i];

        }

    }

    return true;

}

 

int findPages(vector<int>& arr, int n, int m) {

    if (m > n) return -1;

 

    int sum = 0;

    int maxElem = arr[0];

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        maxElem = max(maxElem, arr[i]);

    }

 

    int low = maxElem; 

    int high = sum;    

    int result = -1;

 

    while (low <= high) {

        int mid = low + (high - low) / 2;

 

        if (isPossible(arr, n, m, mid)) {

            result = mid;

            high = mid - 1;

        } else {

            low = mid + 1; 

        }

    }

    return result;

}