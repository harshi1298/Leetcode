class Solution {
public:
    vector<int> dp;

    int solve(int n) {
        if (n == 0)
            return 0;

        if (n < 0)
            return 1e9;

        if (dp[n] != -1)
            return dp[n];

        int ans = 1e9;
        long long sum = 0;

        for (int k = 1; ; k++) {
            sum += k;

            if (sum > n)
                break;

            int remaining = n - sum;

            if (remaining == 0) {
                ans = min(ans, k);
            }
            else {
                ans = min(ans, k + 1 + solve(remaining));
            }
        }

        return dp[n] = ans;
    }

    int minDays(int n) {
        dp.assign(n + 1, -1);

        return solve(n);
    }
};