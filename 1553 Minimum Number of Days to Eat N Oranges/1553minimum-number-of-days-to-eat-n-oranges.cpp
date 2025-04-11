class Solution {
private:
    unordered_map<int,int>dp;
    int solve(int n){
       if(n<=1)return n;
       if(dp.find(n)!=dp.end())return dp[n];
       int ans=INT_MAX;
        ans=min(ans,solve(n/2)+n%2);
        ans=min(ans,solve(n/3)+n%3);
       return dp[n]=ans+1;
    }
public:
    int minDays(int n) {
        return solve(n);
    }
};