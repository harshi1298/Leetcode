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
    ListNode* reverse(ListNode* head, int right,int left){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next=head;
        while(left<right){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            left++;
        }//if(left==1&&right==1) return head;
        head->next=curr;
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* temp=head;
        int i=1;
        while(i<left-1){
            temp=temp->next;
            i++;
        }
        if(left==1) head=reverse(temp,right,0);
        else
        temp->next=reverse(temp->next,right,i);
        return head;
    }
};