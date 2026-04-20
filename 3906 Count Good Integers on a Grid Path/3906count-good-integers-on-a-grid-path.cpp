class Solution {
private:
    long long dp[16][10][2];
    long long solve(string &num,int i,vector<int> &include,int prev,int tight){
        if(i==16){
            return 1;
        }
        if(dp[i][prev][tight]!=-1) return dp[i][prev][tight];
        int en=tight?num[i]-'0':9;
        int start=include[i]?prev:0;
        long long ans=0;
        for(int j=start;j<=en;j++){
            ans+=solve(num,i+1,include,include[i]?j:prev,(tight && j==en)?1:0);
        }
        return dp[i][prev][tight]=ans;
    }
public:
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        memset(dp,-1,sizeof(dp));
        vector<int> reqPos(16,0);
        int i=0;
        reqPos[i]=1;
        for(auto &it:directions){
            if(it=='D'){
                i+=4;
            }
            else i++;
            reqPos[i]=1;
        }
        l--;
        string sl=to_string(l);
        if(sl.length()!=16){
            string s(16-sl.length(),'0');
            s.append(sl);
            sl=s;
        }
        string sr=to_string(r);
        if(sr.length()!=16){
            string s(16-sr.length(),'0');
            s.append(sr);
            sr=s;
        }
        long long rans= solve(sr,0,reqPos,0,1);
        memset(dp,-1,sizeof(dp));
        long long lans=solve(sl,0,reqPos,0,1);
        return rans-lans;
    }
};