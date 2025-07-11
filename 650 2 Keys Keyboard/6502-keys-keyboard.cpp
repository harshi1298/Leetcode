#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<vector<int>> dp;
    int solve(int current, int clipboard, int target)
    {
        if (current == target)
            return 0;
        if (current > target)
            return 1005;
        if (dp[current][clipboard] != -1)
            return dp[current][clipboard];
        int minSteps = 1005;
        minSteps = min(minSteps, 1 + solve(current + clipboard, clipboard, target));
        minSteps = min(minSteps, 2 + solve(current * 2, current, target));
        return dp[current][clipboard] = minSteps;
    }

public:
    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        return 1 + solve(1, 1, n);
    }
};