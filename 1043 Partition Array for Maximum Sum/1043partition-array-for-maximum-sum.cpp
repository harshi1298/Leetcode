class Solution {
private:
    int solve(vector<int>&arr,int k,int i,int j,vector<int>&dp){
        if(i>=j){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int ind=i;
        int count=0;
        int ans=0;
        while(ind<min(i + k, j)){
           count=max(count,arr[ind]);
           ans=max(ans,count*(ind-i+1)+solve(arr,k,ind+1,j,dp));
           ind++;
        }
        return dp[i]=ans;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size(); 
        vector<int>dp(n,-1);
        return solve(arr,k,0,n,dp);
    }
};