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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL||head->next==NULL) return NULL;
        ListNode* temp=head;
        int i=1;
        while(temp!=NULL){
           temp=temp->next;
           i++;
        }
        temp=head;
        int k=1;
        if(i%2!=0){
        while(k<(i/2)){
            temp=temp->next;
            k++;
        }       }
        else{
            while(k<(i/2)-1){
            temp=temp->next;
            k++;
        }  
        }
        temp->next=(temp->next)->next;
        return head;
    }
};