class Solution {
private:
    long long dp[16][160][160][2];
    long long solve(string &s,int even,int odd,int i,int bound){
        if(i>=s.length())return even>0 && even==odd;
        if(dp[i][even][odd][bound]!=-1)return dp[i][even][odd][bound];
        int last=bound==1?s[i]-'0':9;
        long long ans=0;
        for(int j=0;j<=last;j++){
            int newbound=bound && j==s[i]-'0';
            int newodd=odd,neweven=even;
            if(i%2==0){
               newodd=odd+j;
            }
            else neweven=even+j;
            ans+=solve(s,neweven,newodd,i+1,newbound);
        }
        return dp[i][even][odd][bound]=ans;
    }
public:
    long long countBalanced(long long low, long long high) {
        string l=to_string(low-1);
        string h=to_string(high);
       memset(dp, -1, sizeof(dp));
       long long hans= solve(h,0,0,0,1);
       memset(dp, -1, sizeof(dp));
       long long lans= solve(l,0,0,0,1);
       return hans-lans;
    }
};