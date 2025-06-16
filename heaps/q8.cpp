// function to solve the problem of merging k sorted linked lists into one sorted linked list.
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class compare {
public:
    bool operator()(ListNode* a, ListNode* b){ 
        return a -> val > b -> val; 
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    
        for(int i=0;i<lists.size();i++){
            if(lists[i] != NULL){
                pq.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();

            if(top->next){
                pq.push(top->next);
            }

            if(head == NULL){
                head = tail = top; 
            }
            else{
                tail->next = top;
                tail = tail->next;
            }
        }

        return head;
    }
};