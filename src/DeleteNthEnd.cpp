#include <iostream>
#include "ListNode.h"

using namespace std;

// Medium
// the steps is important, maintain the initial condition to the fast/slow ptr
// This helps with the boundary check: fast - slow == n && fast != NULL
// different condition comes with different boundary handling: some would have less check
//
// 1. fast: find the (n+1)th element
//    if it is null, then list only has n element, delete the first ele
// 2. slow ptr to the first ele, if fast->next is not null,continue
// 3. slow ptr th the n+1 ele to the end
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n < 1 || head == NULL){
            return head;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        for(int i = 0; i < n; ++i){
            fast = fast->next;
            if(fast == NULL){
                if(i == n-1)
                    return head->next;
                else{
                    return head;
                }
            }
        }

        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};


int main(int argc, char** argv){
    cout << "hello\n";
}