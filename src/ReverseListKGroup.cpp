#include "ListNode.h"

// Given this linked list: 1->2->3->4->5
// For k = 2, you should return: 2->1->4->3->5
// For k = 3, you should return: 3->2->1->4->5

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *newHead = NULL;
        ListNode *cur = head;

        int len = 0;
        while(cur != NULL){
            len++;
            cur = cur->next;
        }

        if(len < k){
            return head;
        }

        ListNode* preTail = NULL;
        ListNode* tail = NULL;
        ListNode* nxt = NULL;
        cur = head;
        for(int i = 0; i < len/k; ++i){
            // store cur head which is tail after reverse
            tail = cur;
            // return newHead end with NULL,
            // nxt is the next head
            cur = reverseK(cur, k, &nxt);
            if(newHead == NULL) {
                newHead = cur;
            } else {
                preTail->next = cur;
            }

            preTail = tail;
            cur = nxt;
        }

        preTail->next = nxt;
        return newHead;
    }

    // len list must be >= than k
    // return newHead with k node end with NULL
    // nxt: the next head
    ListNode* reverseK(ListNode* head, int k, ListNode** nxt){
        ListNode *newHead = NULL;
        ListNode *cur = head;

        for(int i = 0; i < k; ++i){
            *nxt = cur->next;
            cur->next = newHead;
            newHead = cur;
            cur = *nxt;
        }

        return newHead;
    }
};
