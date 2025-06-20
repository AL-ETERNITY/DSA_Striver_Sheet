// function to solve the problem of counting nodes in a linked list
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

class Solution {
  public:
    int getCount(struct Node* head) {
        int cnt = 1;
        Node* curr = head;
        while(curr -> next){
            cnt++;
            curr = curr->next;
        }
        return cnt;
    }
};