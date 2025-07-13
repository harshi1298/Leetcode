#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<vector<int>> dp;
    int solve(vector<int> &coins, int amount, int i)
    {
        if (amount < 0)
            return INT_MAX;
        if (amount == 0)
            return 0;
        int n = coins.size();
        if (i == n)
            return INT_MAX;
        if (coins[i] > amount)
            return solve(coins, amount, i + 1);
        if (dp[i][amount] != -1)
            return dp[i][amount];
        int include = solve(coins, amount - coins[i], i);
        include = (include == INT_MAX) ? INT_MAX : include + 1;
        int exclude = solve(coins, amount, i + 1);
        return dp[i][amount] = min(include, exclude);
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        // dp.resize(n + 1, vector<int>(amount + 1, -1));
        // int ans = solve(coins, amount, 0);
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j - coins[i - 1] >= 0 && dp[i][j - coins[i-1]] != INT_MAX)
                {
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
                }
            }
        }
        return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
    }
};