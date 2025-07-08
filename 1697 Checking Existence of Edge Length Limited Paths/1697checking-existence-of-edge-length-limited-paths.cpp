#include <bits/stdc++.h>
using namespace std;
#define tp tuple<int, int, int, int>

class Dsu {
public:
    vector<int> par;
    vector<int> size;

    Dsu(int n) {
        par.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }

    int findpar(int x) {
        if (par[x] == x)
            return x;
        return par[x] = findpar(par[x]);
    }

    bool unite(int u, int v) {
        int paru = findpar(u), parv = findpar(v);
        if (paru == parv)
            return false;

        if (size[paru] < size[parv]) {
            par[paru] = parv;
            size[parv] += size[paru];
        } else {
            par[parv] = paru;
            size[paru] += size[parv];
        }
        return true;
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries) {
        Dsu dsu(n);
        sort(edgeList.begin(), edgeList.end(), [&](auto &a, auto &b) {
            return a[2] < b[2];
        });

        vector<tp> temp;
        int i = 0;
        for (auto &it : queries) {
            temp.emplace_back(make_tuple(it[0], it[1], it[2], i));
            i++;
        }

        sort(temp.begin(), temp.end(), [&](const tp &a, const tp &b) {
            return get<2>(a) < get<2>(b);
        });

        vector<bool> ans(queries.size());
        i = 0;
        for (auto &[p, q, l, j] : temp) {
            while (i < edgeList.size() && edgeList[i][2] < l) {
                dsu.unite(edgeList[i][0], edgeList[i][1]);
                i++;
            }
            ans[j] = dsu.findpar(p) == dsu.findpar(q);
        }
        return ans;
    }
};
