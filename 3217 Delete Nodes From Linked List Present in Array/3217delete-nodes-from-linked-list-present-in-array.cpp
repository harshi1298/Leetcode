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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
      unordered_map<int,bool>mapp;
      for(int i=0;i<nums.size();i++){
        mapp[nums[i]]=true;
      }  
      while(head!=NULL && mapp[head->val])head=head->next;
      if(head==NULL)return NULL;
      if(head->next==NULL){
        if(mapp[head->val]){
             return NULL;
        }
        else{
            return head;
        }
      }
      ListNode *temp1=head;
      ListNode *temp2=head->next;
      while(temp2!=NULL){
        if(mapp[(temp2->val)]){
            ListNode* temp=temp2;
            temp1->next=temp2->next;
            temp2=temp2->next;
            delete(temp);
            continue;
        }
        temp1=temp1->next;
        temp2=temp2->next;
      }
      return head;
    }
};