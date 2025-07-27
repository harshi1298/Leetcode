#include <bits/stdc++.h>
using namespace std;
#define tp tuple<int, int, int>
#define pr pair<int, int>

class Solution
{
public:
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &fee)
    {
        int n = fee.size();
        vector<vector<pr>> adj(n);
        for (auto &e : edges)
        {
            int u = e[0], v = e[1], t = e[2];
            adj[u].emplace_back(v, t);
            adj[v].emplace_back(u, t);
        }
        vector<vector<int>> cost(n, vector<int>(maxTime + 1, INT_MAX));
        priority_queue<tp, vector<tp>, greater<tp>> pq;
        pq.emplace(fee[0], 0, 0);
        cost[0][0] = fee[0];

        while (!pq.empty())
        {
            auto [c, u, t] = pq.top();
            pq.pop();

            if (u == n - 1)
                return c;

            for (auto &[v, wt] : adj[u])
            {
                int nt = t + wt;
                if (nt > maxTime)
                    continue;

                int nc = c + fee[v];
                if (cost[v][nt] > nc)
                {
                    cost[v][nt] = nc;
                    pq.emplace(nc, v, nt);
                }
            }
        }

        return -1;
    }
};
