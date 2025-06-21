// function to solve the problem of finding the intersection node of two singly linked lists
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1 != temp2) {
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;

            if(temp1 == temp2) return temp1; // Always exit here (except one case)

            if(temp1 == NULL) temp1 = headB;
            if(temp2 == NULL) temp2 = headA;
        }
        return temp1; // When both Linked lists are same then it will exit here.
    }
};