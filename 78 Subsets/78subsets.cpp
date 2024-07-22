class Solution {
private:
   void solve(vector<int> nums,vector<vector<int>> &ans,vector<int> ans1,int i){
        if(i>=nums.size()){
            ans.push_back(ans1);
             return ;}
        ans1.push_back(nums[i]);
        solve(nums,ans,ans1,i+1);
        ans1.pop_back();
        solve(nums,ans,ans1,i+1);
        
   }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector <int>> ans;
        vector<int> ans1;
        int index=0;
        solve(nums,ans,ans1,index);
        return ans;
    }
};