class Solution {
private:
   void solve(vector<int>nums,vector<int>ans1,vector<vector<int>> &ans,int ind ){
    if(ind==nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=ind;i<nums.size();i++){
       swap(nums[i],nums[ind]);
       solve(nums,ans1,ans,ind+1);
       swap(nums[i],nums[ind]);
    }
   }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ans1;
        vector<vector<int>> ans;
        solve(nums,ans1,ans,0);
        return ans;
    }
};