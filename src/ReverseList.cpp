#include "ListNode.h"

// easy
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL;

        while(head != NULL){
            ListNode* tmp = head->next;
            head->next = newHead;
            newHead = head;
            head = tmp;
        }

        return newHead;
    }
};