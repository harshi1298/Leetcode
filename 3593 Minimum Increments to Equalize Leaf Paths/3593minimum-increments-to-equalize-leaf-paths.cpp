#include <bits/stdc++.h>
using namespace std;
#define pr pair<int, int>

class Solution
{
public:
    int ans = 0;
    long long dfs(int node, int p, vector<vector<int>> &tree, vector<int> &cost)
    {
        vector<long long> csums;

        for (long long  c : tree[node])
        {
            if (c == p)
                continue;
            long long val = dfs(c, node, tree, cost);
            csums.push_back(val);
        }

        if (csums.empty())
            return cost[node];

        long long maxVal = *max_element(csums.begin(), csums.end());

        long long countMax = count(csums.begin(), csums.end(), maxVal);
        ans += (csums.size() - countMax);

        return cost[node] + maxVal;
    }

    int minIncrease(int n, vector<vector<int>> &edges, vector<int> &cost)
    {
        vector<vector<int>> tree(n);
        for (auto &e : edges)
        {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        dfs(0, -1, tree, cost);
        return (int)ans;
    }
};
