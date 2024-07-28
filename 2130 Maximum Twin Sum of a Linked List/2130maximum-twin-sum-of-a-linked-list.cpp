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
    int pairSum(ListNode* head) {
       if(head==NULL) return 0;
        ListNode* temp=head;
        stack<int> a;
        int i=0;
        while(temp!=NULL){
            a.push(temp->val);
            temp=temp->next;
            i++;
        }
        temp=head;
        int max=0;
        while(a.size()>i/2){
         int k=a.top()+temp->val;
         if(max<k) max=k;
         a.pop();
         temp=temp->next;
        }
        return max;
    }
};