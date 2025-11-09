class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>temp={{0,0},{1,1},{2,1}};
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,INT_MIN)));
        for(int i=0;i<=k;i++){
            dp[1][1][i] =temp[grid[0][0]][0];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int x=0;x<=k;x++){
                    if(x-temp[grid[i-1][j-1]][1]>=0){
                      if(dp[i-1][j][x-temp[grid[i-1][j-1]][1]]!=INT_MIN)  
                      dp[i][j][x]=max(dp[i][j][x],dp[i-1][j][x-temp[grid[i-1][j-1]][1]]+temp[grid[i-1][j-1]][0]);
                      if(dp[i][j-1][x-temp[grid[i-1][j-1]][1]]!=INT_MIN) 
                      dp[i][j][x]=max(dp[i][j][x],dp[i][j-1][x-temp[grid[i-1][j-1]][1]]+temp[grid[i-1][j-1]][0]);
                    }
                }
            }
        }
        int ans=INT_MIN;
        for(int x=0;x<=k;x++){
            ans=max(ans,dp[n][m][x]);
        }
        return ans==INT_MIN?-1:ans;
    }
};