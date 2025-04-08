class Solution {
private:
    int solve(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
        if(i+1>=j){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int total_cost=INT_MAX;
        for(int k=i+1;k<j;k++){
            int leftcost=solve(nums,i,k,dp);
            int rightcost=solve(nums,k,j,dp);
            total_cost=min(total_cost,leftcost+rightcost+nums[j]-nums[i]);
        }
        return dp[i][j]=total_cost;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        int size=cuts.size();
        vector<vector<int>>dp(size,vector<int>(size,0));
       for (int i = size - 2; i >= 0; i--) {
        for (int j = 0; j < size; j++) {
            if(i+1>=j){
              continue;
           }
            int total_cost = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                total_cost = min(total_cost,
                                 dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
            }
            dp[i][j] = total_cost;
        }
    }
        return dp[0][size-1];
    }
};