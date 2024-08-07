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
private:
  ListNode* reverse(ListNode* head ,ListNode* &head1){
    if(head->next==NULL){
      head1=head;
      return head;}
     ListNode* k=reverse(head->next,head1);
     k->next=head;
     return head;
  }
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode *head1=NULL;
       ListNode* ans= reverse(head,head1);
        ans->next=NULL;
        return head1;
    }
};