// function to solve insertion sort using recursion
#include<bits/stdc++.h>
using namespace std;

void solveRec(vector<int> &arr, int i) {
    if(i == arr.size()) return;
    
    int key = arr[i];
    int j = i - 1;

    /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j = j - 1;
    }
    arr[j + 1] = key;
    
    solveRec(arr, i + 1);
}

void insertionSort(vector<int>& arr) {
    solveRec(arr, 1);
}