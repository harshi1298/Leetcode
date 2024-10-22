class Solution {
private:
   int solve(vector<int>nums,int t,int s,int i,vector<vector<int>>&dp){
         if(i>=nums.size()){
            if(t==s)return 1;
            return 0;
         }
         if(dp[i][s+1000]!=-1)return dp[i][s+1000];
         int k=solve(nums,t,s+nums[i],i+1,dp);
         int l=solve(nums,t,s-nums[i],i+1,dp);
         return dp[i][s+1000]=k+l;
   } 
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(20001,-1));
        return solve(nums,target,0,0,dp);
    }
};