class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m=obstacleGrid.size();
      int n=obstacleGrid[0].size();
      int ans=0;
       vector<vector<int>>dp(m,vector<int>(n,-1));
       for(int i=0;i<m && !obstacleGrid[i][0];i++)dp[i][0]=1;
       for(int i=0;i<n && !obstacleGrid[0][i];i++)dp[0][i]=1;
       for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(!obstacleGrid[i][j]){
            int k=dp[i-1][j]==-1?0:dp[i-1][j];
            int l=dp[i][j-1]==-1?0:dp[i][j-1];
            dp[i][j]=k+l;
            }
        }
       }
       return dp[m-1][n-1]==-1?0:dp[m-1][n-1];
    }
};