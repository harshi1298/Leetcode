#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int group = 1;
    vector<int> vis;
    void dfs(int i, vector<vector<int>> &adj)
    {
        vis[i] = group;
        for (auto it : adj[i])
        {
            if (!vis[it])
            {
                dfs(it, adj);
            }
        }
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.size();
        vis.resize(n, 0);
        vector<vector<int>> adj(n);
        for (auto &it : pairs)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj);
                group++;
            }
        }
        vector<vector<char>> result(group);
        for (int i = 0; i < n; i++)
        {
            result[vis[i] - 1].push_back(s[i]);
        }
        for (auto &vec : result)
        {
            sort(vec.begin(), vec.end());
            reverse(vec.begin(), vec.end());
        }
        string ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(result[vis[i] - 1].back());
            result[vis[i] - 1].pop_back();
        }
        return ans;
    }
};