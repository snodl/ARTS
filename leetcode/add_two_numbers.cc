/*************************************************
url:https://leetcode.com/problems/add-two-numbers/

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order and each of their nodes contain a single digit. 
  Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.


 * **********************************************/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(-1);
        ListNode*tail=dummy;
        int num=0;
        bool flag=false;
        while(l1 || l2){
            if(flag){
               num=1 ; 
            }else{
                num=0;
            }
            if(l1){
                num+=l1->val;
                l1=l1->next;
            }
            if(l2){
                num+=l2->val;
                l2=l2->next;
            }
            if(num>9){
                num-=10;
                flag=true;
            }else{
                flag=false;
            }
            tail->next=new ListNode(num);
            tail= tail->next;
                
        }
       
        if(flag){
            tail->next=new ListNode(1);
            tail= tail->next;
        }
        return dummy->next;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*head=NULL,**tmp=&head;
        int num=0;
        bool flag=false;
        while(l1 || l2){
            if(flag){
               num=1 ; 
            }else{
                num=0;
            }
            if(l1){
                num+=l1->val;
                l1=l1->next;
            }
            if(l2){
                num+=l2->val;
                l2=l2->next;
            }
            if(num>9){
                num-=10;
                flag=true;
            }else{
                flag=false;
            }
           *tmp=new ListNode(num);
            tmp= &((*tmp)->next);
                
        }
       
        if(flag){
            *tmp=new ListNode(1);
            tmp= &((*tmp)->next);
        }
        return head;
    }
};