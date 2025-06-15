#include <bits/stdc++.h>
#define pr pair<double, int>
using namespace std;
class Solution
{
private:
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &sp, int start, int end)
    {
        vector<vector<pr>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            auto it = edges[i];
            int u = it[0];
            int v = it[1];
            adj[u].push_back(make_pair(sp[i], v));
            adj[v].push_back(make_pair(sp[i], u));
        }
        priority_queue<pr> pq;
        pq.push(make_pair(1, start));
        vector<double> dis(n, -DBL_MAX);
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (d < dis[u])
                continue;
            for (auto [w, v] : adj[u])
            {
                if (dis[v] < d * w)
                {
                    dis[v] = d * w;
                    pq.push(make_pair(d * w, v));
                }
            }
        }
        return dis[end] == -DBL_MAX ? 0 : dis[end];
    }
};