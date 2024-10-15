class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>>dp(row,vector<int>(col,0));
        for(int i=0;i<col;i++)dp[row-1][i]=matrix[row-1][i];
        for(int i=row-2;i>=0;i--){
            for(int j=0;j<col;j++){
                int k=dp[i+1][j];
                int l=j==0?1e9:dp[i+1][j-1];
                int m=j==col-1?1e9:dp[i+1][j+1];
                dp[i][j]=matrix[i][j]+min(k,min(l,m));
            }
        }
        int ans=1e9;
        for(int i=0;i<row;i++){
            ans=min(ans,dp[0][i]);
        }
       return ans;
    }
};