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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        if(list1==NULL)
         return list2;
        if(list2==NULL)
         return list1;
        int i=0;
        ListNode* temp1=list1;
        ListNode* temp2=list1;
        while(i<a-1){
            temp1=temp1->next;i++;
        }
        temp2=temp1;
        while(i<=b){
        temp2=temp2->next;i++;}
        temp1->next=list2;
        while(list2->next!=NULL)
           list2=list2->next;
        list2->next=temp2;
        return list1;
    }
};