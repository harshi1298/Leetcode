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
    ListNode* mergetwolist(ListNode* head1,ListNode* head2){
        if(head1==NULL)return head2;
        if(head2==NULL)return head1;
        ListNode *temp=new ListNode(-1);
        ListNode* tail=temp;
          while (head1!= NULL && head2!= NULL){
              if(head1->val<=head2->val){
                tail->next=head1;
                head1=head1->next;
              }
              else{
                tail->next=head2;
                head2=head2->next;
              }
              tail=tail->next;
          }
          if(head1==NULL){
            tail->next=head2;
          }
          else tail->next=head1;
        return temp->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        ListNode* ans=lists[0];
       for(int i=1;i<lists.size();i++){
           ans=mergetwolist(ans,lists[i]);
       }
       return ans;
    }
};