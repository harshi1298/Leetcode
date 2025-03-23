class Solution {
private:
    int solve(int x,int y,vector<vector<int>>& coins,int neu){
        if(x==coins.size()-1 && y==coins[0].size()-1){
            if(neu<2) return max(0,coins[x][y]);
            return coins[x][y];
        }
        else if(x>=coins.size() || y>=coins[0].size()) return INT_MIN;
        int ans=coins[x][y]+max(solve(x+1,y,coins,neu),solve(x,y+1,coins,neu));
        if(neu<2) ans=max(ans,solve(x+1,y,coins,neu+1));
        if(neu<2) ans=max(ans,solve(x,y+1,coins,neu+1));
        return ans;
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size();
        int n=coins[0].size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(3,-1e7)));
        dp[1][1][0]=coins[0][0];
        dp[1][1][1]=max(0,coins[0][0]);
        dp[1][1][2]=max(0,coins[0][0]);
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                for(int k=0;k<3;k++){
                    if(i==1 && j==1) continue;
                dp[i][j][k]=max(dp[i-1][j][k],dp[i][j-1][k])+coins[i-1][j-1];

                    if(k>0){
                        dp[i][j][k]=max({dp[i][j][k],dp[i-1][j][k-1],dp[i][j-1][k-1]});
                    }
                }

            }
        }
        return dp[m][n][2];
    }
};