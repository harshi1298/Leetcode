class Solution {
private:
    int solve(const vector<int>& prices, int i, int canBuy,
              vector<vector<int>>& dp) {
        // Base case: if we're past the last stock, no profit can be made
        if (i == prices.size())
            return 0;
        if (dp[i][canBuy] != -1)
            return dp[i][canBuy];
        if (canBuy) {
            return dp[i][canBuy] = max(-prices[i] + solve(prices, i + 1, 0, dp),
                                       solve(prices, i + 1, 1, dp));
        } else {
            return dp[i][canBuy] = max(prices[i] + solve(prices, i + 1, 1, dp),
                                       solve(prices, i + 1, 0, dp));
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        // return solve(prices, 0, 1, dp);
        int maxprofit = 0;
        int n = prices.size();
        for(int i = 1; i<n; i++){
            if(prices[i]>prices[i-1]){
                maxprofit += prices[i] - prices[i-1];
            }
        }
        return maxprofit;
    }
};
