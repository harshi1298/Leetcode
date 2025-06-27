#include <bits/stdc++.h>
using namespace std;
class dsu
{
private:
    vector<int> par;
    vector<int> rank;

public:
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
    bool check(int u, int v)
    {
        if (find(u) == find(v))
            return true;
        return false;
    }
};
class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {

        dsu ds(26);
        vector<string> temp;
        for (auto it : equations)
        {
            if (it[1] == '!')
            {
                temp.push_back(it);
            }
            else
            {
                ds.findunion(it[0] - 'a', it[3] - 'a');
            }
        }
        for (auto it : temp)
        {
            if (ds.check(it[0] - 'a', it[3] - 'a'))
                return false;
        }
        return true;
    }
};