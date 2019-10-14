#include "ListNode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode dumhead(0);
        dumhead.next = head;

        ListNode *slow = &dumhead;
        ListNode *fast = &dumhead;

        while(slow && fast){
            slow = slow->next;
            fast = fast->next;
            if(fast)
                fast = fast->next;
        }

        return slow;
    }
};
