class Solution {
private:
    vector<vector<int>>dp;
    int solve(vector<pair<int,int>> & arr,int i,int sum){
        int n=arr.size();
        if(sum>=n){
            return 0;
        }
        if(i>=n){
            return 1e9;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        int ans=1e9;
        if(sum+arr[i].second+1<=n){
            ans=min(ans,arr[i].first+solve(arr,i+1,sum+arr[i].second+1));
        }
        else{
            ans=min(ans,arr[i].first+solve(arr,i+1,n));
        }
        ans=min(ans,solve(arr,i+1,sum));
        return dp[i][sum]=ans;
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<pair<int,int>>arr;
        int n=cost.size();
        dp.assign(n,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            arr.push_back({cost[i],time[i]});
        }
        int ans=solve(arr,0,0);
        return ans;
    }
};