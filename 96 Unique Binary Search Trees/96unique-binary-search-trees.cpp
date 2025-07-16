class Solution {
private:
    vector<int> dp;
    int memo(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += memo(i) * memo(n - 1 - i);
        }
        return dp[n] = ans;
    }
public:
    int numTrees(int n) {
        // dp.resize(n + 1, -1);
        // return memo(n);
        dp.resize(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
};