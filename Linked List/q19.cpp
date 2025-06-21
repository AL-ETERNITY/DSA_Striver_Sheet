// Function to solve the problem of removing the nth node from the end of a linked list.
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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        int cnt = 0;
        ListNode* temp = head;
        while (temp) {
            cnt++;
            temp = temp->next;
        }

        ListNode* curr = head;
        for (int i = 0; i < (cnt / 2) - 1; i++) {
            curr = curr->next;
        }

        ListNode* toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete;

        return head;
    }
};
