#include <bits/stdc++.h>
using namespace std;
#define pr pair<int, int>
#define tp tuple<int, int, int>
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &fl, int src, int dst, int k)
    {
        vector<vector<pr>> adj(n);
        for (auto it : fl)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back(make_pair(w, v));
        }
        vector<vector<int>> dis(n, vector<int>(k + 2, INT_MAX));
        priority_queue<tp, vector<tp>, greater<tp>> pq;
        pq.emplace(0, src, 0);
        dis[src][0] = 0;
        while (!pq.empty())
        {
            auto [d, u, l] = pq.top();
            pq.pop();
            if (d > dis[u][l])
                continue;
            if(l>k)continue;
            for (auto [w, v] : adj[u])
            {
                if (dis[v][l + 1] > d + w)
                {
                    dis[v][l + 1] = d + w;
                    pq.emplace(d + w, v, l + 1);
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i <= k+1; i++)
        {
            ans = min(ans, dis[dst][i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};