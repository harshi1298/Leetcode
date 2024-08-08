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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0 || head->next==NULL) return head;
        ListNode* temp=head;
        int l=1;
        while(temp->next!=NULL){
            l++;
            temp=temp->next;
        }
        temp->next=head;
         k=k%l;
        l=l-k;
        ListNode*tmp=head;
        while(l--){
           head=head->next;
           if(l==1)tmp=head;
        }
        tmp->next=NULL;
        return head;
    }
};