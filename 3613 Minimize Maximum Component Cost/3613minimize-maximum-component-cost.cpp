class Dsu{
    public:
    vector<int>par,rank;
    Dsu(int n){
        par.resize(n,0);
        rank.resize(n,1);
        for(int i=0;i<n;i++)par[i]=i;
    }
    int find(int u){
        if(par[u]==u)return u;
        return par[u]=find(par[u]);
    }
    bool unite(int u,int v){
        int paru=find(u),parv=find(v);
        if(paru==parv){
            return false ;
        }
        if(rank[paru]>rank[parv]){
            par[parv]=paru;
        }
        else if(rank[paru]<rank[parv]){
            par[paru]=parv;
        }
        else {
            rank[paru]++;
            par[parv]=paru;
        }
        return true;
    }
};
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        Dsu dsu(n);
        sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
    return a[2] < b[2];
});

        int ans=0;
        for(auto &it : edges){
            int u=it[0];
            int v=it[1];
            if(n==k)break;
            if(dsu.unite(u,v)){
                n--;
                ans=it[2];
            }
        }
        return ans;
    }
};