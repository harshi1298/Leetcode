class Solution {
private:
    int dp[101][2][201];
    int solve(vector<int>&piles,int i,int ch,int m){
        int n=piles.size();
        if(i>=n)return 0;
        if(dp[i][ch][m]!=-1) return dp[i][ch][m];
        int count=0;
        int ans=0;
        if(ch==0){
            for(int j=0;j<2*m && i+j<n;j++){
            count+=piles[j+i];
            ans=max(ans,count+solve(piles,j+i+1,1,max(j+1,m)));
           }
        }
        else{
            ans=INT_MAX;
            for(int j=0;j<2*m && i+j<n;j++){
            ans=min(ans,solve(piles,j+1+i,0,max(j+1,m)));
           }
        }
        return dp[i][ch][m]= ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int n=piles.size();
        return solve(piles,0,0,1);
    }
};