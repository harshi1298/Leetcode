class Solution {
private:
    int solve(string &s,int i,int j,int k, vector<vector<vector<int>>>&dp){
        if(i>=j){
           return i==j;
        }
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        int count=0,b;
        if(s[i]==s[j]){
           count=2+solve(s,i+1,j-1,k,dp);
        }
       else if ((b = min(abs(s[i] - s[j]), 26 - abs(s[i] - s[j]))) <= k) {
          count = max(count, 2 + solve(s, i + 1, j - 1, k - b,dp));
       }

       count=max({count,solve(s,i+1,j,k,dp),solve(s,i,j-1,k,dp)});
        return dp[i][j][k]=count;
    }
public:
    int longestPalindromicSubsequence(string s, int k) {
        vector<vector<vector<int>>>dp(s.length(),vector<vector<int>>(s.length(),vector<int>(k+1,-1)));
        return solve(s,0,s.length()-1,k,dp);
    }
};