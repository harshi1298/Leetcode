#include <bits/stdc++.h>
using namespace std;
class DSU
{
public:
    vector<int> parent;
    DSU(int n)
    {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y)
    {
        parent[find(x)] = find(y);
    }
};

class Solution
{
public:
    vector<int> processQueries(int c, vector<vector<int>> &connections, vector<vector<int>> &queries)
    {
        DSU dsu(c);
        for (auto &con : connections)
        {
            int u = con[0], v = con[1];
            dsu.unite(u, v);
        }
        unordered_map<int, set<int>> st;
        for (int i = 1; i <= c; i++)
        {
            int root = dsu.find(i);
            st[root].insert(i);
        }
        vector<bool> prs(c + 1, true);
        vector<int> res;
        for (auto &q : queries)
        {
            int t = q[0], x = q[1];
            int root = dsu.find(x);
            if (t == 1)
            {
                if (prs[x])
                {
                    res.push_back(x);
                }
                else
                {
                    auto &s = st[root];
                    if (s.empty())
                    {
                        res.push_back(-1);
                    }
                    else
                    {
                        res.push_back(*s.begin());
                    }
                }
            }
            else if (t == 2)
            {
                if (prs[x])
                {
                    prs[x] = false;
                    st[root].erase(x);
                }
            }
        }
        return res;
    }
};
