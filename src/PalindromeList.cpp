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
    bool isPalindrome(ListNode* head) {
        int count = 0;
        ListNode *tmp = head;

        while(tmp != NULL){
            ++count;
            tmp = tmp->next;
        }

        ListNode* second = NULL;
        ListNode* first = reverseN(head, count/2, &second);

        if(count % 2) second = second->next;

        while(first && second){
            if(first->val != second->val)
                return false;

            first = first->next;
            second = second->next;
        }

        return true;
    }

    // reverse the first n element and return
    // save the rest of the list in next
    // assume list is longer than n
    ListNode* reverseN(ListNode *head, int n, ListNode** next){
        ListNode *first = NULL;

        for(int i = 0; i < n; ++i){
            ListNode* tmp = head->next;
            head->next = first;
            first = head;
            head = tmp;
        }

        *next = head;
        return first;
    }
};

int main(int argc, char** argv){
    Solution s;

    return 0;
}