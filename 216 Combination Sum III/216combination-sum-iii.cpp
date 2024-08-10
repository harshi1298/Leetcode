class Solution {
private:
   void solve(vector<int> nums,int index,vector<int>ans1,vector<vector<int>> &ans,int  n,int k,int sum){
    if(ans1.size()==k || index==9){
        if(sum==n && ans1.size()==k)
        ans.push_back(ans1);
        return ;
    } 
       ans1.push_back(nums[index]);
       sum+=nums[index];
       solve(nums,index+1,ans1,ans,n,k,sum);
       sum-=nums[index];
       ans1.pop_back();
       solve(nums,index+1,ans1,ans,n,k,sum);
   }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums={1,2,3,4,5,6,7,8,9};
        vector<int> ans1; 
        vector<vector<int>> ans;
        solve(nums,0,ans1,ans,n,k,0);
        return ans;
    }
};