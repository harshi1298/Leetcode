class DSU{
public: 
   vector<int>rank;
   vector<int>parent;
   DSU(int n){
    rank.resize(n,0);
    parent.resize(n,1);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
   }

    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu!=pv){
            if(rank[pu]>rank[pv]){
                parent[pv]=pu;
            }
            else if(rank[pu]<rank[pv]){
                parent[pu]=pv;
            }
            else {
                parent[pv]=pu;
                rank[pu]++;
            }
        }
    }
};
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](auto &a, auto &b) {
            return a[2] < b[2];
        });

        DSU dsu(n);
        dsu.unite(0, firstPerson);

        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];
            vector<int> people;
            while (i < meetings.size() && meetings[i][2] == time) {
                int x = meetings[i][0];
                int y = meetings[i][1];
                dsu.unite(x, y);
                people.push_back(x);
                people.push_back(y);
                i++;
            }
            for (int p : people) {
                if (dsu.find(p) != dsu.find(0)) {
                    dsu.parent[p] = p;   
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == dsu.find(0)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
