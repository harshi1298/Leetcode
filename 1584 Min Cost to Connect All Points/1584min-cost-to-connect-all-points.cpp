#include <bits/stdc++.h>
using namespace std;
#define pr pair<int, int>
class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        vector<vector<pr>> adj(n);
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        for (int i = 0; i < n; i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i; j < n; j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int w = abs(x2 - x1) + abs(y2 - y1);
                adj[i].push_back(make_pair(w, j));
                adj[j].push_back(make_pair(w, i));
            }
        }
        vector<int> vis(n, 0);
        int ans = 0;
        pq.push(make_pair(0, 0));
        while (!pq.empty())
        {
            auto [w, u] = pq.top();
            pq.pop();
            if (!vis[u])
            {
                vis[u] = 1;
                ans += w;
                for (auto [w1, v] : adj[u])
                {
                    if (!vis[v])
                    {
                        pq.push(make_pair(w1, v));
                    }
                }
            }
        }
        return ans;
    }
};