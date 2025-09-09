class Solution {
public:
    int mod=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long>dp(n+1);
        dp[1]=1;
        for(int i=0;i<=n;i++){
           for(int j=i+delay;j<=min(n,i+forget-1);j++){
            dp[j]+=dp[i];
            dp[j]%=mod;
           }
        }
        long long ans=0;
        for(int i=n,j=0;j<forget;j++,i--){
            ans+=dp[i];
            ans%=mod;
        }
        return ans;
    }
};