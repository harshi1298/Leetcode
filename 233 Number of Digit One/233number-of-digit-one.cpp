class Solution {
private:
    int dp[10][2][10];
    int solve(string s,int flag,int count,int i){
        if(i>=s.length())return count;
        if(dp[i][flag][count]!=-1)return dp[i][flag][count];
        int last_d=flag?s[i]-'0':9;
        int ans=0;
        for(int j=0;j<=last_d;j++){
            int updated_count=count+(j==1);
            ans+=solve(s,(flag && j==last_d),updated_count,i+1);
        }
        return dp[i][flag][count]=ans;
    }
public:
    int countDigitOne(int n) {
        string str=to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(str,1,0,0);
    }
};