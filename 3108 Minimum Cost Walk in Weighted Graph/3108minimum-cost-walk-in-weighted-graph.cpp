class DisjointSet{
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int findparent(int x){
        if(parent[x] != x) {
            parent[x] = findparent(parent[x]); 
        }
        return parent[x];
    }

    void Union(int x, int y){
        int u = findparent(x);
        int v = findparent(y);
        if(u == v) return;
        if(rank[u] < rank[v]) {
            parent[u] = v;
        } else if(rank[u] > rank[v]) {
            parent[v] = u;
        } else {
            parent[u] = v;
            rank[v]++;
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
       DisjointSet dsu=DisjointSet(n);
       for(auto it :edges){
        dsu.Union(it[0],it[1]);
       }
       vector<int>temp(n+1,INT_MAX);
       for(auto it :edges){
        int parent=dsu.findparent(it[0]);
        temp[parent]=temp[parent]&it[2];
       }
       vector<int>ans;
       for(auto it:query){
        if(dsu.findparent(it[0])!=dsu.findparent(it[1])){
            ans.push_back(-1);
        }
        else {
            ans.push_back(temp[dsu.findparent(it[0])]);
        }
       }
       return ans;
    }
};