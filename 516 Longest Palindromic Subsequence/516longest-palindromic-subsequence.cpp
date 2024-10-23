class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2=s;
        reverse(s.begin(),s.end());
        vector<vector<int>>dp(s.length()+1,vector<int>(s2.length()+1,0));
        for(int i=s.length()-1;i>=0;i--){
            for(int j=s2.length()-1;j>=0;j--){
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
               if(s[i]==s2[j]){
                dp[i][j]=max(dp[i][j],1+dp[i+1][j+1]);
               }
            }
        }
        return dp[0][0];
    }
};