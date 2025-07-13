#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<long long> dp;
    int solve(vector<int> &nums, int target)
    {
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;
        if (dp[target] != -1)
            return dp[target];
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans += solve(nums, target - nums[i]);
        }
        dp[target] = ans;
        return ans;
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        // dp.resize(target + 1, -1);
        // return solve(nums, target);
        dp.assign(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i - nums[j] >= 0 && dp[i]<=INT_MAX && dp[i-nums[j]]<=INT_MAX)
                {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};