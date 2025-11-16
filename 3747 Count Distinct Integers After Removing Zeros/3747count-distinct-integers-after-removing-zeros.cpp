class Solution {
private:
    long long dp[17][2][2];
    long long solve(int pos,int tight,string num,int st){
        if(pos==num.length())return st;
        if(dp[pos][tight][st]!=-1)return dp[pos][tight][st];
        long long ans=0;
        int limit=tight?(num[pos]-'0'):9;
        for(int d=0;d<=limit;d++){
            if(st && d==0)continue;
            int newst = st;
            if(d > 0) newst = 1;
            ans+=solve(pos+1,tight && (d==limit),num,newst);
        }
        return dp[pos][tight][st]=ans;
    }
public:
    long long countDistinct(long long n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,1,to_string(n),0);
    }
};