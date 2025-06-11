#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<vector<int>> adj;
    int count = 0;
    vector<int> vis;
    void dfs(int i)
    {
        vis[i] = 1;
        for (auto it : adj[i])
        {
            if (!vis[it])
                dfs(it);
        }
        count++;
    }

public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        vector<int> group;
        adj.resize(n);
        for (auto it : edges)
        {
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vis.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i);
                group.push_back(count);
                count = 0;
            }
        }
        int gs = group.size();
        long long temp = 0;
        long long ans = 0;
        for (int i = gs - 1; i > 0; i--)
        {
            temp += group[i];
            ans += (group[i - 1] * temp);
        }
        return ans;
    }
};