class Solution {
private:
    int solve(string ring,int idx,int i,string key,vector<vector<int>>&dp){
        int n=key.length();
        if(i>=n)return 0;
        if(dp[idx][i]!=-1)return dp[idx][i];
        int m=ring.length();
        int ans=0;
        for(int j=0;j<m;j++){
            if(ring[(idx+j)%m]==key[i]){
              ans=j+solve(ring,(idx+j)%m,i+1,key,dp);
              break;
            }
        }
        for(int j=0;j<m;j++){
            if(ring[(idx-j+m)%m]==key[i]){
              ans=min(ans,j+solve(ring,(idx-j+m)%m,i+1,key,dp));
              break;
            }
        }
        return dp[idx][i]= ans;
    }
public:
    int findRotateSteps(string ring, string key) {
        int n=ring.size(),m=key.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(ring,0,0,key,dp)+key.length();
    }
};