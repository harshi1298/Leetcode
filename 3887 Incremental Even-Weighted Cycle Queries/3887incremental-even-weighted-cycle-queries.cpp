class DSU {
public:
    vector<int> parent, rank, parity;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        parity.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    pair<int,int> find(int x) {
        if(parent[x] == x) return {x, 0};

        auto res = find(parent[x]);
        parent[x] = res.first;
        parity[x] ^= res.second;  
        return {parent[x], parity[x]};
    }

    bool unite(int x, int y, int w) {
        auto [px, px_par] = find(x);
        auto [py, py_par] = find(y);

        if(px == py) {
            if((px_par ^ py_par) != w) {
                return false;
            }
            return true;
        }
        if(rank[px] < rank[py]) {
            parent[px] = py;
            parity[px] = px_par ^ py_par ^ w;
        } 
        else {
            parent[py] = px;
            parity[py] = px_par ^ py_par ^ w;
            if(rank[px] == rank[py]) rank[px]++;
        }
        return true;
    }
};
class Solution {
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        int ans=0;
        DSU dsu(n);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w=e[2];
            if(dsu.unite(u, v,w)){
                ans++;
            }
        }
        return ans;
    }
};