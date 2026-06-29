class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
       long long dp[3][n];
       memset(dp,0,sizeof(dp));
        dp[0][0]=1ll*nums[0];
        dp[1][0]=1ll*nums[0]*k;
        dp[2][0]=LLONG_MIN/4;
        long long ans=max({dp[0][0],dp[1][0]});
        for(int i=1;i<n;i++){
            dp[0][i]=max(dp[0][i-1]+1ll*nums[i],1ll*nums[i]);
            dp[1][i]=max({dp[1][i-1],dp[0][i-1],0ll})+1ll*nums[i]*k;
            dp[2][i]=max(dp[2][i-1]+1ll*nums[i],dp[1][i-1]+1ll*nums[i]);
            ans=max({ans,dp[0][i],dp[1][i],dp[2][i]});
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=nums[0];
        dp[1][0]=nums[0]/k;
        dp[2][0]=LLONG_MIN/4;
        ans=max({ans,dp[0][0],dp[1][0]});
        for(int i=1;i<n;i++){
            dp[0][i]=max(dp[0][i-1]+1ll*nums[i],1ll*nums[i]);
            dp[1][i]=max({dp[1][i-1],dp[0][i-1],0ll})+1ll*nums[i]/k;
            dp[2][i]=max(dp[2][i-1]+1ll*nums[i],dp[1][i-1]+1ll*nums[i]);
            ans=max({ans,dp[0][i],dp[1][i],dp[2][i]});
        }
        return ans;
    }
};