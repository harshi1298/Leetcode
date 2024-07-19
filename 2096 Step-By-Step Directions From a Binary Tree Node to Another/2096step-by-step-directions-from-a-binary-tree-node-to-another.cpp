/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
  void searchstart(TreeNode* root,int target,TreeNode* &ans){
    if(root==NULL) return;
      if(root->val==target){
        ans=root;
        return;
      }
      searchstart(root->left,target,ans);
      searchstart(root->right,target,ans);
     return ;
  }

  void ansdirection(TreeNode* start,int startvalue, int des, int &flag1,int &flag2,string &ans1,string &ans2){
    if(start==NULL) return ;
    if(start->val==startvalue) flag1=1;
    if(start->val==des) flag2=1;
     if(!flag1) ans1+='L';
     if(!flag2) ans2+='L';
    ansdirection(start->left,startvalue,des,flag1,flag2,ans1,ans2);
    if(!flag1) ans1.pop_back();
    if(!flag2) ans2.pop_back();
     if(!flag1) ans1+='R';
    if(!flag2) ans2+='R';
   ansdirection(start->right,startvalue,des,flag1,flag2,ans1,ans2);
    if(!flag1) ans1.pop_back();
    if(!flag2) ans2.pop_back();
  }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
    //     TreeNode *start=NULL;
    //    searchstart(root,startValue,start);
    //    cout<<start->val;
    //    int flag=0;
       string ans1="",ans2="",ans="";
       int flag1=0,flag2=0;
       ansdirection(root,startValue,destValue,flag1,flag2,ans1,ans2);
       int i=0;
       cout<<ans1<<" "<<ans1.length()<<ans2<<" "<<ans2.length()<<endl;
       while(ans1[i]==ans2[i]) i++;
       int l=i;
       while(i<ans1.length()) {
        ans+='U';
        i++;
       }
       while(l<ans2.length()){
        ans+=ans2[l++];
       }
       cout<<ans;
       return ans;
    }
};