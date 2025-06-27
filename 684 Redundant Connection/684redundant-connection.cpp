#include <bits/stdc++.h>
using namespace std;
class dsu
{
private:
    vector<int> par;
    vector<int> rank;

public:
    vector<int> ans;
    dsu(int n)
    {
        par.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }

    int find(int u)
    {
        if (par[u] == u)
            return u;
        return par[u] = find(par[u]);
    }

    void findunion(int u, int v)
    {
        int paru = find(u);
        int parv = find(v);
        if (paru == parv)
        {
            ans = {u+1, v+1};
            return;
        }
        if (rank[paru] > rank[parv])
        {
            par[parv] = paru;
        }
        else if (rank[paru] < rank[parv])
        {
            par[paru] = parv;
        }
        else
        {
            par[paru] = parv;
            rank[parv] += 1;
        }
        return;
    }
};
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        dsu ds(n);
        for (auto it : edges)
        {
            ds.findunion(it[0]-1, it[1]-1);
        }
        return ds.ans;
    }
};