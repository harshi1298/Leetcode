class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,1));
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                for(int l=0;l<=k;l++){
                    if(nums[i]!=nums[j] && l>0){
                        dp[i][l]=max(dp[i][l],1+dp[j][l-1]);
                    }
                    else if(nums[i]==nums[j]){
                        dp[i][l]=max(dp[i][l],1+dp[j][l]);
                    }
                    ans=max(ans,dp[i][l]);
                }
            }
        }
        return ans;
    }
};
;