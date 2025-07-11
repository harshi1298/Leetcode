#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int solve(vector<int> nums, int index, vector<int> &dp)
    {
        if (index >= nums.size())
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int l = solve(nums, index + 1, dp);
        int r = nums[index] + solve(nums, index + 2, dp);
        return dp[index] = max(l, r);
    }

public:
    int rob(vector<int> &nums)
    {
        // vector<int> dp(nums.size(), -1);
        // return solve(nums, 0, dp);
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            int l = dp[i + 1];
            int r = nums[i] + (i + 2 < n ? dp[i + 2] : 0);
            dp[i] = max(l, r);
        }
        return dp[0];
    }
};