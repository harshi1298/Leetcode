#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int solve(vector<int> &dp, vector<int> &nums, int i)
    {
        if (i >= nums.size() - 1)
            return 0;
        if (nums[i] == 0)
            return INT_MAX;
        if (dp[i] != INT_MAX)
            return dp[i];

        for (int j = 1; j <= nums[i]; ++j)
        {
            int temp = solve(dp, nums, i + j);
            if (temp == INT_MAX)
                continue;
            dp[i] = min(dp[i], temp + 1);
        }
        return dp[i];
    }

public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i)
        {
            if (nums[i] == 0)
            {
                dp[i] = INT_MAX;
                continue;
            }
            for (int j = 1; j <= nums[i] && i + j < n; ++j)
            {
                if (dp[i + j] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[i + j] + 1);
                }
            }
        }
        return dp[0];
    }
};