#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int i, string &s, vector<int> &dp)
    {
        if (i == s.length())
            return 1;

        if (s[i] == '0')
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = solve(i + 1, s, dp);

        if (i + 1 < s.length())
        {
            string temp = s.substr(i, 2);
            int t = stoi(temp);
            if (t >= 10 && t <= 26)
                ans += solve(i + 2, s, dp);
        }

        return dp[i] = ans;
    }

public:
    int numDecodings(string s)
    {
        int n = s.length();
        // vector<int> dp(n, -1);
        // return solve(0, s, dp);
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
                continue;
            dp[i]= dp[i + 1];
            if (i + 2 <=n)
            {
                string temp = s.substr(i, 2);
                int t = stoi(temp);
                if (t >= 10 && t <= 26)
                    dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }
};
