class Solution {
private:
    vector<vector<int>>dp;
    bool solve(int i,int j,int l,string s1,string s2,string s3){
        int n=s1.length(),m=s2.length(),k=s3.length();
        if(i==n && j==m && i+j==k)return dp[i][j]=true;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s3[l] && solve(i+1,j,l+1,s1,s2,s3))return dp[i][j]=true;
        if(s2[j]==s3[l] && solve(i,j+1,l+1,s1,s2,s3))return dp[i][j]=true;
        return dp[i][j]=false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
         int n=s1.length(),m=s2.length(),k=s3.length();
         if(n+m!=k)return false;
        dp.assign(n+1,vector<int>(m+1,-1));
        return solve(0,0,0,s1,s2,s3);
    }
};