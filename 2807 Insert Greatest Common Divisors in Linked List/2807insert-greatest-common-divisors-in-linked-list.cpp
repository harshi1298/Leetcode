/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* curr=head,*next=head->next;               
   while(next!=NULL){
    int val=gcd(curr->val,next->val);
    ListNode* newnode=new ListNode(val);
    newnode->next=next;
    curr->next=newnode;
    curr=next;
    next=next->next;
   }
   return head;
    }
};