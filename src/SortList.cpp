#include "ListNode.h"
#include <iostream>

using namespace std;

//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
//      ListNode(int x, ListNode* nxt) : val(x), next(nxt) {}
//  };

// Medium, partition & merge
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head) return head;

        int n = 0;
        ListNode* tmp = head;
        while(tmp != NULL){
            n++;
            tmp = tmp->next;
        }

        return sortList(head, n, &tmp);
    }

    ListNode* sortList(ListNode* head, int count, ListNode** nxt) {
        if(count == 1){
            *nxt = head->next;
            head->next = NULL;
            return head;
        }

        ListNode* n1 = NULL;
        ListNode* h1 = sortList(head, count / 2, &n1);
        ListNode* h2 = sortList(n1, count - count/2, nxt);

        return merge(h1, h2);
    }

    ListNode* merge(ListNode* h1, ListNode* h2){
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
            }
            else{
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
    ListNode n1(5);
    ListNode n2(6);
    ListNode n3(3);

    n1.next = &n2;
    n2.next = &n3;

    ListNode* h = s.sortList(&n1);

    cout << h->val << endl;
    cout << h->next->val << endl;
    cout << h->next->next->val << endl;
    return 0;
}