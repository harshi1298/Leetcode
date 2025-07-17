class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
          int n=nums.size();
       vector<vector<int>>dp(k,vector<int>(n,1));
       for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
           int t=(nums[i]+nums[j])%k;
           dp[t][i]=max(dp[t][i],dp[t][j]+1);
        }
       }
       int maxLength = 1;
       for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            maxLength=max(maxLength,dp[j][i]);
        }
       }
        return maxLength; 
    }
};