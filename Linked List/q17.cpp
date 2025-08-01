// function to solve the problem of checking if a linked list is a palindrome
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head -> next) return head;

        ListNode* odd = head;
        ListNode* even = head -> next;
        ListNode* evenHead = even;
        while(odd && even && even -> next) {
            odd -> next = even -> next;
            odd = odd -> next;
            if(even -> next){
                even -> next = even -> next -> next;
                even = even -> next;
            }
        }
        odd -> next = evenHead;
        return head;
    }
};