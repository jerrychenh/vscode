 #include<stdlib.h>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
     ListNode(int x, ListNode* nxt) : val(x), next(nxt) {}
 };