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
    int getDecimalValue(ListNode* head) {
        ListNode* temp=head;
        int count=0;
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        int ans=0;
        while(head!=NULL){
            ans=ans+(head->val)*(pow(2,count));
            head=head->next;
            count--;
        }
        return ans;
    }
};