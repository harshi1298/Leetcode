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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        priority_queue<pair<int,ListNode*>>pq;
        while(list1!=NULL){
            pq.push({list1->val,list1});
            list1=list1->next;
        }
        while(list2!=NULL){
           pq.push({list2->val,list2});
            list2=list2->next;
        }
        ListNode* temp=new ListNode(-1);
        while(!pq.empty()){
            ListNode* tmp=temp->next;
            temp->next=pq.top().second;
            pq.top().second->next=tmp;
            pq.pop();
        }
        return temp->next;
    }
};