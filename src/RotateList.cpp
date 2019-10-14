#include "ListNode.h"


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode *tmp = head;
        ListNode *tail = NULL;

        while(tmp != NULL){
            ++len;
            tail = tmp;
            tmp = tmp->next;
        }

        if(len < 2){
            return head;
        }

        k %= len;
        if(k == 0)
            return head;

        // get the len - k node
        // loop invariant: tmp at the ith node
        tmp = head;
        for(int i = 1; i < len - k; ++i){
            tmp = tmp->next;
        }

        tail->next = head;
        head = tmp->next;
        tmp->next = NULL;
        return head;
    }
};