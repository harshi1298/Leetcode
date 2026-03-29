class Solution {
private:
    int solve(vector<vector<int>>& grid,int i,int j,int Xor,vector<vector<vector<int>>>&dp){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=n || j>=m)return 1e4;
        int nxor=grid[i][j]^Xor;
        if(dp[i][j][Xor]!=-1)return dp[i][j][Xor];
        if(i==n-1 && j==m-1)return nxor;
        int ans=solve(grid,i+1,j,nxor,dp);
        ans=min(ans,solve(grid,i,j+1,nxor,dp));
        return dp[i][j][Xor]=ans;
    }
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(1024,-1)));
        return solve(grid,0,0,0,dp);
    }
};