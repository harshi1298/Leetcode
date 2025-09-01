class Solution {
private:
    vector<vector<int>>dp;
    bool solve(string &s,string &p,int i,int j){
        if(i==s.length()){
            while(j<p.length() && p[j]=='*') j++;
            return  dp[i][j]=j==p.length();
        }
        else if(i>=s.length() || j>=p.length() )return  dp[i][j]=0;
        else{
            if(dp[i][j]!=-1)return dp[i][j];
            if(s[i]==p[j] || p[j]=='?'){
                return dp[i][j]=solve(s,p,i+1,j+1);
            }
            else{
                if(p[j]=='*'){
                     bool flag=0;
                    flag=solve(s,p,i+1,j+1)|| solve(s,p,i,j+1) || solve(s,p,i+1,j);
                    if(flag)return dp[i][j]= 1;
                }
            }
        }
       
        return dp[i][j]=0;
    }
public:
    bool isMatch(string s, string p) {
        int l1=s.length(),l2=p.length();
        dp.resize(l1+1,vector<int>(l2+1,-1));
        return solve(s,p,0,0);
    }
};