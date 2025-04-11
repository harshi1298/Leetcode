class Solution {
private:
    int solve(vector<string>& strs, int i,int m, int n, vector<vector<vector<int>>>&dp){
        if(i>=strs.size())return 0;
        if(dp[i][m][n]!=-1)return dp[i][m][n];
        int ans=0;
       int t = count(strs[i].begin(), strs[i].end(), '0');
        if(m>=t &&( strs[i].length()-t<=n)){
            ans=max(ans,1+solve(strs,i+1,m-t,n-(strs[i].length()-t),dp));
        }
        ans=max(ans,solve(strs,i+1,m,n,dp));
        return dp[i][m][n]=ans;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(strs,0,m,n,dp);
    }
};
