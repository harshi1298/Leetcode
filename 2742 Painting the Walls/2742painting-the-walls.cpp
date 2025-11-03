class Solution {
private:
    vector<vector<int>>dp;
    int solve(vector<pair<int,int>> & arr,int i,int sum){
        int n=arr.size();
        if(i>=n){
            if(sum>=0)return 0;
            return INT_MAX;
        }
        if(dp[i][sum+500]!=-1)return dp[i][sum+500];
        int ans=INT_MAX;
        int tsum=sum+arr[i].second>501?501:sum+arr[i].second;
        int t=solve(arr,i+1,tsum);
        ans=min(ans,t==INT_MAX?INT_MAX:arr[i].first+t);
        ans=min(ans,solve(arr,i+1,sum-1));
        return dp[i][sum+500]=ans;
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<pair<int,int>>arr;
        int n=cost.size();
        dp.assign(n,vector<int>(1002,-1));
        for(int i=0;i<n;i++){
            arr.push_back({cost[i],time[i]});
        }
        return solve(arr,0,0);
    }
};