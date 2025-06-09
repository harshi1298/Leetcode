#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumOperationsToWriteY(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> belong(3, 0), nonbelong(3, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i == j && i <= n / 2) || (i + j == n - 1 && i <= n / 2) || (j == n / 2 && i >= n / 2))
                {
                    belong[grid[i][j]]++;
                }
                else
                    nonbelong[grid[i][j]]++;
            }
        }
        int ans = n * n;
        ans = min(ans, belong[1] + belong[2] + nonbelong[0] + nonbelong[2]);
        ans = min(ans, belong[1] + belong[2] + nonbelong[0] + nonbelong[1]);
        ans = min(ans, belong[0] + belong[2] + nonbelong[1] + nonbelong[2]);
        ans = min(ans, belong[0] + belong[2] + nonbelong[1] + nonbelong[0]);
        ans = min(ans, belong[0] + belong[1] + nonbelong[0] + nonbelong[2]);
        ans = min(ans, belong[0] + belong[1] + nonbelong[1] + nonbelong[2]);
        return ans;
    }
};