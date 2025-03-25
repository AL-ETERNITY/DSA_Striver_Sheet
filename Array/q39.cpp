#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int cnt = 0; 
    void merge(vector<int>& nums, int s, int e) {

        int mid = (s+e)/2;

        int len1 = mid - s + 1;
        int len2 = e - mid;

        vector<int> first(len1);
        vector<int> second(len2);

        //copy values
        int mainArrayIndex = s;
        for(int i=0; i<len1; i++) {
            first[i] = nums[mainArrayIndex++];
        }

        mainArrayIndex = mid+1;
        for(int i=0; i<len2; i++) {
            second[i] = nums[mainArrayIndex++];
        }

        //merge 2 sorted arrays     
        int index1 = 0;
        int index2 = 0;
        mainArrayIndex = s;

        while(index1 < len1 && index2 < len2) {
            if(first[index1] < second[index2]) {
                nums[mainArrayIndex++] = first[index1++];
            }
            else{
                nums[mainArrayIndex++] = second[index2++];
            }
        }   

        while(index1 < len1) {
            nums[mainArrayIndex++] = first[index1++];
        }

        while(index2 < len2 ) {
            nums[mainArrayIndex++] = second[index2++];
        }

    }

    void countPairs(vector<int>& nums, int s, int e){
        int mid = (s+e)/2;
        int right = mid + 1;
        for(int i=s;i<=mid;i++){
            while(right <= e && nums[i] > 2*(long long)nums[right]){
                right++;
            }
            cnt += (right - (mid+1));
        }
    }

    void mergeSort(vector<int>& nums, int s, int e) {

        //base case
        if(s >= e) {
            return;
        }
        
        int mid = (s+e)/2;

        //left part sort karna h 
        mergeSort(nums, s, mid);
        
        //right part sort karna h 
        mergeSort(nums, mid+1, e);

        // count reverse pairs
        countPairs(nums,s,e);

        //merge
        merge(nums, s, e);

    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);
        return cnt;
    }
};