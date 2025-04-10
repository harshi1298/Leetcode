class Solution {
private:
    long long dp[20][2];
    long long solve(string &s,long long i,bool allowed,long long limit,string &t){
        if(dp[i][allowed]!=-1) return dp[i][allowed];
        if(s.length()<t.length()) return 0;
        else if(i+(long long)t.length()==(long long)s.length()){
            if(!allowed) return s.substr(i)>=t;
            return 1;
        }
        long long last=allowed?limit:s[i]-'0';
        long long ans=0;
        for(long long j=0;j<=min(limit,last);j++){
            ans+=solve(s,i+1,allowed || s[i]-'0'!=j,limit,t);
        }
        return dp[i][allowed]=ans;
    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, long long limit, string s) {
        memset(dp,-1,sizeof(dp));
        string a1=to_string(finish);
        long long ans=solve(a1,0,0,limit,s);
        memset(dp,-1,sizeof(dp));
        string a2=to_string(start-1);
        ans-=solve(a2,0,0,limit,s);
        return ans;
    }
};