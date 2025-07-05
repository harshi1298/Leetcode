#include <bits/stdc++.h>
using namespace std;

#define tp tuple<long long, int, int, int> // cost, i, j, sec

class Solution
{
public:
    long long minCost(int m, int n, vector<vector<int>> &waitCost)
    {
        priority_queue<tp, vector<tp>, greater<>> pq;
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX)));

        dp[0][0][1] = 1;
        pq.push({1LL, 0, 0, 1});

        while (!pq.empty())
        {
            auto [cost, i, j, sec] = pq.top();
            pq.pop();

            if (cost > dp[i][j][sec%2])
                continue;

            if (i == m - 1 && j == n - 1)
                continue;

            if (sec % 2 == 1)
            {
                int dx[] = {1, 0};
                int dy[] = {0, 1};

                for (int k = 0; k < 2; k++)
                {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 0 && nj >= 0 && ni < m && nj < n)
                    {
                        long long temp = cost + (long long)(ni + 1) * (nj + 1);
                        if (temp < dp[ni][nj][0])
                        {
                            dp[ni][nj][0] = temp;
                            pq.push({temp, ni, nj, sec + 1});
                        }
                    }
                }
            }
            else
            {
                long long temp = cost + (long long)waitCost[i][j];
                if (temp < dp[i][j][1])
                {
                    dp[i][j][1] = temp;
                    pq.push({temp, i, j, sec + 1});
                }
            }
        }

        return min(dp[m - 1][n - 1][0], dp[m - 1][n - 1][1]);
    }
};
