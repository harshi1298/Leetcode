#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 1;
        vector<vector<int>> dp(n, vector<int>(2, 1));
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
                else if (nums[i] < nums[j])
                {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
            }
            ans = max({ans, dp[i][0], dp[i][1]});
        }
        return ans;
    }
};