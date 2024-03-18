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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        // ListNode *l1=NULL;
        // while(l1!=NULL ){
        //     ListNode *node=new ListNode;
        //     node->next=temp1;
        //     temp1=node;
        //     node->val=l1->val;
        //     l1=l1->next;
        // }
        // ListNode *l2=NULL;
        // while(l2!=NULL ){
        //     ListNode *node=new ListNode;
        //     node->next=l2;
        //     temp2=node;
        //     node->val=l2->val;
        //     l2=l2->next;
        // }
        if(l1==NULL && l2==NULL){
            ListNode *node=new ListNode;
            node->val=0;
            return node;
        }
        ListNode *temp3=NULL;
        while(l1!=NULL &&l2!=NULL){
            ListNode *node=new ListNode;
          node->next=temp3;
          node->val=((l1->val)+(l2->val)+carry)%10;
          carry=((l1->val)+(l2->val)+carry)/10;
          temp3=node;
          l1=l1->next;
          l2=l2->next;
        }
        while(l1!=NULL){
            ListNode *node=new ListNode;
          node->next=temp3;
          node->val=((l1->val)+carry)%10;
          carry=((l1->val)+carry)/10;
          temp3=node; 
          l1=l1->next;
        }
         while(l2!=NULL){
            ListNode *node=new ListNode;
          node->next=temp3;
          node->val=(((l2->val))+carry)%10;
          carry=((l2->val)+carry)/10;
          temp3=node; 
          l2=l2->next;
        }
        if(carry){
            ListNode *node=new ListNode;
          node->next=temp3;
          node->val=1;
          carry=0;
          temp3=node; 
        }
        ListNode *head=NULL;
        while(temp3!=NULL ){
            ListNode *node=new ListNode;
            node->next=head;
            head=node;
            node->val=temp3->val;
            temp3=temp3->next;
        }
        return head;
    }
};