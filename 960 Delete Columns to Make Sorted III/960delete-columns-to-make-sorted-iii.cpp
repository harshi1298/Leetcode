class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int l=strs[0].length();
        vector<int>dp(l+1,1);
        int ans=1;
        for(int i=1;i<l;i++){
           for(int j=0;j<i;j++){
            bool flag=true;
            for(int k=0;k<n;k++){
                if(strs[k][i]<strs[k][j])flag=false;
            }
            if(flag){
                dp[i]=max(dp[i],dp[j]+1);
            }
           }
           ans=max(ans,dp[i]);
        }
        return l-ans;
    }
};