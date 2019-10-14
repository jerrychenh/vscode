#include "ListNode.h"
#include <vector>

using namespace std;
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;

        for (int i = 0; i + 1 < lists.size(); i += 2){
            lists.push_back(mergeList(lists[i], lists[i + 1]));
        }

        return lists[lists.size() - 1];
    }

    ListNode* mergeList(ListNode *h1, ListNode *h2){
        if(!h1) return h2;
        if(!h2) return h1;

        ListNode *head = NULL;
        ListNode *cur = NULL;

        while(h1 && h2){
            if(h1->val <= h2->val){
                if(head == NULL){
                    head = h1;
                    cur = h1;
                } else {
                    cur->next = h1;
                    cur = h1;
                }
                h1 = h1->next;
            } else {
                if(head == NULL){
                    head = h2;
                    cur = h2;
                } else {
                    cur->next = h2;
                    cur = h2;
                }
                h2 = h2->next;
            }
        }

        if(h1){
            cur->next = h1;
        }

        if(h2){
            cur->next = h2;
        }

        return head;
    }
};


int main(int argc, char** argv){
    Solution s;

    return 0;
}