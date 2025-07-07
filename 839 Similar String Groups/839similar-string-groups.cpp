#include <bits/stdc++.h>
using namespace std;
class Dsu
{
private:
    vector<int> par, rank;

public:
    Dsu(int n)
    {
        par.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }
    int find(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    bool unite(int u, int v)
    {
        int paru = find(u);
        int parv = find(v);
        if (paru == parv)
            return true;
        if (rank[paru] < rank[parv])
        {
            par[paru] = parv;
        }
        else if (rank[paru] > rank[parv])
        {
            par[parv] = paru;
        }
        else
        {
            par[paru] = parv;
            rank[parv]++;
        }
        return false;
    }
};
class Solution
{
private:
    bool isSimilar(string a, string b)
    {
        vector<int> temp;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] != b[i])
                temp.push_back(i);
        }
        if(temp.size()==0)return true;
        if (temp.size() != 2)
            return false;
        if (a[temp[0]] == b[temp[1]] && a[temp[1]] == b[temp[0]])
            return true;
        return false;
    }

public:
    int numSimilarGroups(vector<string> &strs)
    {
        int n = strs.size();
        Dsu dsu(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isSimilar(strs[i], strs[j]))
                {
                    dsu.unite(i, j);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (dsu.find(i) == i)
            {
                ans++;
            }
        }
        return ans;
    }
};