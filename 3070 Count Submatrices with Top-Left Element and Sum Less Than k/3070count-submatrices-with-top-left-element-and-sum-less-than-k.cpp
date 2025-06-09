#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<vector<long long>> prefixSum(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<vector<long long>> ps(n, vector<long long>(m, 0));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                ps[i][j] = mat[i][j] + (i > 0 ? ps[i - 1][j] : 0) + (j > 0 ? ps[i][j - 1] : 0) - (i > 0 && j > 0 ? ps[i - 1][j - 1] : 0);

        return ps;
    }

public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        vector<vector<long long>> temp = prefixSum(grid);
        int ans = 0;
        int n = grid.size();
        long long sum = 0;
        for (auto it : grid)
        {
            if (sum + it[0] <= k)
            {
                ans++;
                sum += it[0];
            }
            else break;
        }
        sum = grid[0][0];
        for (int i = 1; i < grid[0].size(); i++)
        {
            if (sum + grid[0][i] <= k)
            {
                ans++;
                sum += grid[0][i];
            }
            else
                break;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < grid[0].size(); j++)
            {
                if (temp[i][j] <= k)
                    ans++;
            }
        }
        return ans;
    }
};