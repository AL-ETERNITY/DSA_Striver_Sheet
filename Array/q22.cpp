#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    void reverse(vector<int>& nums, int start) {
        int i = start;
        int j = nums.size() - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }

public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            reverse(nums, 0);
            return; 
        }

        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums, i, index);
                break;
            }
        }
        
        reverse(nums, index + 1);
    }
};
