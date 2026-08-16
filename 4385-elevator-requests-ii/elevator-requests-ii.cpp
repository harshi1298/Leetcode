class Solution {
private:
    int n;
    long long dp[1502][1502][2];
    long long solve(int left,int right,vector<int>&arr,int rend){
        if (left==0 && right==n-1)return 0;
        if(dp[left][right][rend]!=-1)return dp[left][right][rend];
        long long ans=LLONG_MAX;
        int pos=rend==0?arr[left]:arr[right];
        int num=left+(n-right-1);
        if(left>0)ans=min(ans,1ll*(pos-arr[left-1])*num+solve(left-1,right,arr,0));
        if(right<n-1)ans=min(ans,1ll*(arr[right+1]-pos)*num+solve(left,right+1,arr,1));
        return dp[left][right][rend]=ans;
    }
public:
    long long elevatorRequests(int na, int start, vector<int>& req) {
        req.push_back(start);
        sort(req.begin(),req.end());
        n=req.size();
        memset(dp,-1,sizeof(dp));
        auto it=lower_bound(req.begin(),req.end(),start)-req.begin();
        return solve(it,it,req,0);
    }
};