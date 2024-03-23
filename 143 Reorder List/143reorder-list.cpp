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
    void reorderList(ListNode* head) {
    if(head==NULL||head->next==NULL||head->next->next==NULL)
      return;
       int i=0;
    ListNode* temp=head;
    while(temp!=NULL){
    temp=temp->next;
    i++;}
    int j=i-1;
    vector<ListNode*>ptr;
    while(head!=NULL){
        ptr.push_back(head);
      head=head->next;
      }
      i=0;
      while (i < j) {
            ptr[i]->next = ptr[j];
            ptr[j]->next = NULL;
             i++;
            if(i<j){
            ptr[j]->next = ptr[i];
            ptr[i]->next = NULL;
            j--;}
        }
        i--;
        head=ptr[0]; 
        return;
    }
};