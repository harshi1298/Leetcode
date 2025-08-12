class Solution {
public:
    int mod=1e9+7;
    int numberOfWays(int n, int x) {
        vector<int>arr;
        for(int i=1;(int)(pow(i,x))<=n;i++){
            arr.push_back((int)(pow(i,x)));
        }
        int size=arr.size();
        vector<vector<int>>dp(size+1,vector<int>(n+1));
        for(int i=0;i<=size;i++)dp[i][0]=1;
        for(int i=1;i<=size;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i-1][j];
                int temp=j-(int)(pow(i,x));
                if(temp>=0){
                    dp[i][j]+=dp[i-1][temp];
                }
                dp[i][j]%=mod;
            }
        }
        return dp[size][n];
    }
};