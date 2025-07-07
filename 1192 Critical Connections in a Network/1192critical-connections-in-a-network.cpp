#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<int> vis, low, disc;
    vector<vector<int>> adj, ans;
    int timer = 0;
    void dfs(int node, int parent)
    {
        vis[node] = 1;
        disc[node] = low[node] = timer++;
        for (int neighbor : adj[node])
        {
            if (neighbor == parent)
                continue;
            if (!vis[neighbor])
            {
                dfs(neighbor, node);
                low[node] = min(low[node], low[neighbor]);
                if (low[neighbor] > disc[node])
                {
                    ans.push_back({node, neighbor});
                }
            }
            else
            {
                low[node] = min(low[node], disc[neighbor]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vis.resize(n);
        low.resize(n);
        disc.resize(n);
        adj.resize(n);
        for (auto &conn : connections)
        {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        dfs(0, -1);
        return ans;
    }
};
