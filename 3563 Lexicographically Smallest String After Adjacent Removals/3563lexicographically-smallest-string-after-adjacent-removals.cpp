class Solution {
public:
    string lexicographicallySmallestString(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n - 1; i++) {
            if (abs(s[i] - s[i + 1]) == 1 || abs(s[i] - s[i + 1]) == 25) {
                dp[i][i + 1] = 1;
            }
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if ((abs(s[i] - s[j]) == 1 || abs(s[i] - s[j]) == 25) && dp[i + 1][j - 1]) {
                    dp[i][j] = 1;
                    continue;
                }
                for (int k = i; k < j; k++) {
                    if (dp[i][k] && dp[k + 1][j]) {
                        dp[i][j] = 1;
                        break;
                    }
                }
            }
        }
        vector<string> dp2(n + 1, "");
        for (int i = n - 1; i >= 0; --i) {
            dp2[i] = s[i] + dp2[i + 1]; 
            for (int j = i + 1; j < n; ++j) {
                if (dp[i][j]) {
                    dp2[i] = min(dp2[i], dp2[j + 1]);
                }
            }
        }

        return dp2[0];
    }
};
