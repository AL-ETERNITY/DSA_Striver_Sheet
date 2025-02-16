#include <bits/stdc++.h>
using namespace std;

int numberOfGasStation(vector<int> v, long double distance) {
  int cnt = 0;
  for (int i = 1; i < v.size(); i++) {
    int numberInBetween = (v[i] - v[i - 1]) / distance;
    if ((v[i] - v[i - 1]) / distance == numberInBetween * distance) {
      numberInBetween--;
    }
    cnt += numberInBetween;
  }
  return cnt;
}
double minimiseMaxDistance(vector<int> &arr, int k) {
  int n = arr.size();
  long double low = 0;
  long double high = 0;
  for (int i = 0; i < n; i++) {
    high = max(high, (long double)(arr[i + 1] - arr[i]));
  }
  long double diff = 1e-6;
  while (high - low > diff) {
    long double mid = (low + high) / 2.0;
    int cnt = numberOfGasStation(arr, mid);
    if (cnt > k) {
      low = mid;
    } else {
      high = mid;
    }
  }
  return high;
}