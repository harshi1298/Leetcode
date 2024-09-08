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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp=head;
        int length=0;
        while(temp){
            length++;
            temp=temp->next;
        }
        int mod=length%k;
        int gsize=length/k;
        if(gsize==0){gsize++;mod=0;}
        temp=head;
        int count=1;
        vector<ListNode*>ans;
        while(temp!=NULL){
           if(count==1){
             ans.push_back(temp);
           }
           if(count==gsize){
             if(mod){
                temp=temp->next;
                mod--;
             }
             ListNode* tmp=temp->next;
             temp->next=NULL;
             temp=tmp;
             count=1;
             continue;
           }
           temp=temp->next;
           count++;
        }
        while(ans.size()<k){
            ans.push_back(NULL);
        }
        return ans;
    }
};