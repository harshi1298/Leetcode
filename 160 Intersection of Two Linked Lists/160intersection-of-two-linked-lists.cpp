/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode *temp2=headB;
        int l1=0,l2=0;
        while(temp1!=NULL){
            l1++;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            l2++;
            temp2=temp2->next;
        }
        ListNode *tmp1=l1>=l2?headA:headB;
        ListNode *tmp2=l1<l2?headA:headB;
        int k=l1>l2?l1-l2:l2-l1;
        while(k--){
           tmp1=tmp1->next;
        }
        while(tmp1!=tmp2){
            tmp1=tmp1->next;
            tmp2=tmp2->next;
        }
        return tmp1;
    }
};