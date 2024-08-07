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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *evenhead=NULL,*oddhead=NULL;
        ListNode* temp=head;
        ListNode *tmp1=head;
        ListNode *tmp2=head;
        while(temp!=NULL && temp->next!=NULL){
           if(oddhead==NULL){
            oddhead=temp;
            tmp1=temp;
           }
           if(evenhead==NULL){
            evenhead=temp->next;
            tmp2=temp->next;
           }
          else{
             tmp1->next=temp;
             tmp1=temp;
             tmp2->next=temp->next;
             tmp2=temp->next;
          }
           cout<<temp->val<<" ";
          temp=temp->next->next;
        }
        if(temp!=NULL){
            tmp1->next=temp;
            tmp1=temp;
        }
        tmp1->next=evenhead;
        tmp2->next=NULL;
        return oddhead;
    }
};