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
    ListNode* swapnode(ListNode* head){
        if(head==NULL)
         return NULL;
        if(head->next==NULL)
         return head;
        ListNode* curr=head;
        ListNode* next=head->next;
        ListNode* prev=next->next;
        next->next=curr;
        curr->next=swapnode(prev);
        return next;

    }
public:
    ListNode* swapPairs(ListNode* head) {
        head=swapnode(head);
        return head;
    }
};