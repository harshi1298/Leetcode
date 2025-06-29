#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &nums, int i, int k, vector<vector<int>> &dp)
    {
        int n = nums.size();
        if (k == 0)
        {
            if (i == n)
                return 0;
            return 2e9;
        }
        if (i == n)
        {
            return 2e9;
        }
        if (dp[i][k] != 2e9 + 1)
            return dp[i][k];
        int ans = 2e9;
        int xr = 0;
        for (int j = i; j < n; ++j)
        {
            xr ^= nums[j];
            int next = solve(nums, j + 1, k - 1,dp);
            ans = min(ans, max(xr, next));
        }
        return dp[i][k] = ans;
    }

    int minXor(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(k+2, 2e9 + 1));
        return solve(nums, 0, k, dp);
    }
};