#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int solve(vector<int> &nums, int st, int end, bool chan)
    {
        if (st > end)
            return 0;
        if (chan == 0)
        {
            return max(nums[st] + solve(nums, st + 1, end, 1), nums[end] + solve(nums, st, end - 1, 1));
        }
        else
        {
            return min(solve(nums, st + 1, end, 0), solve(nums, st, end - 1, 0));
        }
    }

public:
    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();
        // int total = accumulate(nums.begin(), nums.end(), 0);
        // return ((total + 1) / 2 < solve(nums, 0, n - 1, 0));
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = nums[i];
        }
        for (int diff = 1; diff < n; diff++)
        {
            for (int i = 0; i < n-diff; i++)
            {
                int j = i + diff;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1]>=0;
    }
};