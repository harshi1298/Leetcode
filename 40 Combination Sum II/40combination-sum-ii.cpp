class Solution {
private:
   void solve(vector<int> &nums,int index,vector<int>ans1,vector<vector<int>> &ans,int  n){
    if(n==0|| index==nums.size()){
        if(n==0)
        ans.push_back(ans1);
        return ;
    } 
    for(int i=index;i<nums.size();i++){
        if(i>index && nums[i]==nums[i-1])continue;
         if (nums[i] > n) break;
       ans1.push_back(nums[i]);
       solve(nums,i+1,ans1,ans,n-nums[i]);
       ans1.pop_back();
    }
   }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> ans1;
        vector<vector<int>> ans;
        solve(candidates,0,ans1,ans,target);
        return ans;
    }
};