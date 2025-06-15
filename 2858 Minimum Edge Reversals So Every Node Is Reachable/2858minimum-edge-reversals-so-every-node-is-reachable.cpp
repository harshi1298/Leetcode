#include <bits/stdc++.h>
using namespace std;
#define pr pair<int, int>
class Solution
{
private:
    vector<int> ans;
    vector<int> vis;
    vector<vector<pr>> adj;
    void dfs(int i)
    {
        vis[i] = 1;
        for (auto [w, it] : adj[i])
        {
            if (!vis[it])
            {
                if (w == 0)
                {
                    ans[it] = ans[i] + 1;
                }
                else
                    ans[it] = ans[i] - 1;
                dfs(it);
            }
        }
    }

public:
    vector<int> minEdgeReversals(int n, vector<vector<int>> &edges)
    {
        adj.resize(n);
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(make_pair(0, v));
            adj[v].push_back(make_pair(1, u));
        }
        vector<int> dis(n, INT_MAX);
        dis[0] = 0;
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        pq.push(make_pair(0, 0));
        vector<int>temp(n,0);
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dis[u])
                continue;
            for (auto [w, v] : adj[u])
            {
                if (dis[v] > d + w)
                {
                    dis[v] = d + w;
                    temp[v]=w;
                    pq.push(make_pair(d + w, v));
                }
            }
        }
        ans.resize(n);
        vis.resize(n);
        ans[0]=accumulate(temp.begin(),temp.end(),0);
        dfs(0);
        return ans;
    }
};