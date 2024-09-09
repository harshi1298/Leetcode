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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>ans(m,vector<int>(n,-1));
        int left=0,right=n,up=0,down=m;
        while(head){
            for(int i=left;i<right && head;i++){
                ans[up][i]=head->val;
                head=head->next;
            }
            up++;
            for(int i=up;i<down && head;i++){
                ans[i][right-1]=head->val;
                head=head->next;
            }
            right--;
            for(int i=right-1;i>=left && head;i--){
                ans[down-1][i]=head->val;
                head=head->next;
            }
            down--;
            for(int i=down-1;i>=up && head;i--){
                ans[i][left]=head->val;
                head=head->next;
            }
            left++;
        }
        return ans;
    }
};