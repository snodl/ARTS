/**************************
url:https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

***************************/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return NULL;
        }
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* first=dummy;
        ListNode* second=head;
        for(int i=0;i<n && second;i++){
            second=second->next;
        }
        while(second){
            second=second->next;
            first=first->next;
        }
        first->next=first->next->next;
        return dummy->next;
    }
};