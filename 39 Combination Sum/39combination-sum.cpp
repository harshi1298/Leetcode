class Solution {
private:
   void solve(vector<int> &nums,vector<int>ans1,vector<vector<int>> &ans,int  n,int sum){
    if(sum>=n){
        sort(ans1.begin(),ans1.end());
        if(sum==n)
        ans.push_back(ans1);
        return ;
    } 
    for(int i=0;i<nums.size();i++){
        // if (i > 0 && nums[i] == nums[i - 1]) {
        //         continue;
        //     }
       ans1.push_back(nums[i]);
       sum+=nums[i];
       solve(nums,ans1,ans,n,sum);
       sum-=nums[i];
       ans1.pop_back();
    }
   }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> ans1;
        vector<vector<int>> ans;
        solve(candidates,ans1,ans,target,0);
        set<vector<int>>s;
        for(int i=0;i<ans.size();i++) s.insert(ans[i]);
         vector<vector<int> >ans2(s.begin(),s.end());
        return ans2;
    }
};