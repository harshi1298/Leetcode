class Solution {
private: 
    vector<vector<int>>dp;
    int solve(int st,int end,vector<int>&piles,int ch){
        if(st>end)return 0;
        if(dp[st][end]!=-1)return dp[st][end];
        if(ch==0){
            return dp[st][end]=max(piles[st]+solve(st+1,end,piles,1),piles[end]+solve(st,end-1,piles,1));
        }
        else{
            return dp[st][end]= min(solve(st+1,end,piles,0),solve(st,end-1,piles,0));
        }
    }
public:
    bool stoneGame(vector<int>& piles) {
        int total=accumulate(piles.begin(),piles.end(),0);
        int n=piles.size();
        dp.resize(n,vector<int>(n,-1));
        return (total+1)/2<=solve(0,n-1,piles,0);
    }
};