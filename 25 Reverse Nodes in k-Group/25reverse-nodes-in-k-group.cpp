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
    ListNode* reverse(ListNode* head, int k){
        int i=0;
        ListNode* temp=head;
        while(temp!=NULL&&i<=k){
            i++;
            temp=temp->next;
        }
        if(i<k)  return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next;
        i=0;
        while(i<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            i++;
        }
        head->next=reverse(curr,k);
        return prev ;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        head=reverse(head,k);
        return head;
    }
};