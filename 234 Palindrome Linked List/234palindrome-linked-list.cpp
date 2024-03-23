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
    bool isPalindrome(ListNode* head) {
        vector<int>pld;
        int i=0;
        while(head!=NULL){
            pld.push_back(head->val);
            head=head->next;
            i++;
        }
        int j=i-1;
        i=0;
        while(i<j){
            if(pld[i]==pld[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
};