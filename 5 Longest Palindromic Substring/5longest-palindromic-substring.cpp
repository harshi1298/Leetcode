#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.length(), maxlen = 0, idx = -1;
        string t = s;
        reverse(s.begin(), s.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)

        {
            for (int j = 1; j <= n; j++)
            {
                if (t[i - 1] == s[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (i - dp[i][j] == n - j && maxlen < dp[i][j])
                {
                    maxlen = dp[i][j];
                    idx = i - maxlen;
                }
            }
        }
        return t.substr(idx, maxlen);
    }
};