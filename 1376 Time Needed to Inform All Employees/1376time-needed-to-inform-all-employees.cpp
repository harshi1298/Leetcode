#include <bits/stdc++.h>
using namespace std;
#define pr pair<int, int>
vector<int> depth;
class Solution
{
private:
    vector<vector<int>> adj;
    void dfs(int i, vector<int> &timer)
    {
        int best = 0;
        bool leaf = 1;
        for (auto it : adj[i])
        {
            leaf = 0;
            dfs(it, timer);
            best = max(best, depth[it]);
        }
        if (leaf)
            depth[i] = 0;
        else
            depth[i] = timer[i] + best;
    }

public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        adj.resize(n);
        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
            {
                adj[manager[i]].push_back(i);
            }
        }
        depth.resize(n);
        dfs(headID, informTime);
        return depth[headID];
    }
};