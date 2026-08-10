class Solution {
private:
    vector<int>dp;
    int solve(vector<int>&arr,int i){
       int n=arr.size();
       if(dp[i]!=-1e9)return dp[i];
       if(i>=n)return 0;
       long long sum=0,ans=INT_MIN;
       for(int j=0;j<3 && i+j<n;j++){
          sum+=arr[i+j];
          ans=max(ans,sum-solve(arr,i+j+1));
       }
       return dp[i]=ans;
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        dp.resize(n+1,-1e9);
        int ans=solve(stoneValue,0);
        if(ans==0)return "Tie";
        else if(ans>0)return "Alice";
        return "Bob";
    }
};