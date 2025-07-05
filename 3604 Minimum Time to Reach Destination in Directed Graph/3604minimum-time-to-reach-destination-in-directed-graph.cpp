#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTime(int n, vector<vector<int>> &edges)
    {
        vector<vector<tuple<int, int, int>>> adj(n);
        for (auto &e : edges)
        {
            adj[e[0]].emplace_back(e[1], e[2], e[3]);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto [time, u] = pq.top();
            pq.pop();

            if (u == n - 1)
                return time;

            if (time > dist[u])
                continue;

            for (auto &[v, s, e] : adj[u])
            {
                int temp = max(time, s);
                if (temp <= e && temp + 1 < dist[v])
                {
                    dist[v] = temp + 1;
                    pq.push({temp + 1, v});
                }
            }
        }
        return -1;
    }
};
