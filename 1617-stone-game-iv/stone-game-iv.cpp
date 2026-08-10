class Solution {
private:
    vector<int>square;
    vector<int>dp;
    bool solve(int n){
        if(n==0)return false;
        if(dp[n]!=-1)return dp[n];
        for(int i=0;i<square.size();i++){
            if(square[i]>n)break;
            if(!solve(n-square[i]))return dp[n]=true;
        }
        return dp[n]=false;
    }
public:  
    bool winnerSquareGame(int n) {
        vector<bool>seive(n+1,1);
        seive[1]=seive[0]=0;
        dp.resize(n+2,-1);
        for(int i=1;i*i<=n;i++){
            square.push_back(i*i);
        }
        return solve(n);
    }
};