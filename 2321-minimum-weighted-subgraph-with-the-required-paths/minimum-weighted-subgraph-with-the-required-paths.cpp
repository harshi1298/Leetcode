class Solution {
private:
    vector<vector<pair<int,int>>>adj;
    vector<vector<pair<int,int>>>revadj;
    vector<long long> solve(int src,int flag){
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        pq.push({0,src});
        int n=adj.size();
        vector<long long>dist(n,LLONG_MAX);
        dist[src]=0;
        while(!pq.empty()){
            auto [we,u]=pq.top();
            pq.pop();
            if(dist[u]!=we)continue;
            for(auto [v,nw] :flag? adj[u]: revadj[u]){
                if(dist[v]>1ll*nw+1ll*we){
                    dist[v]=1ll*nw+1ll*we;
                    pq.push({nw+we,v});
                }
            }
        }
        return dist;
    }
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        adj.resize(n+1);
        revadj.resize(n+1);
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            revadj[v].push_back({u,w});
        }
        vector<long long>s1=solve(src1,1);
        vector<long long >s2=solve(src2,1);
        vector<long long >des=solve(dest,0);
        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++){
           if(s1[i]==LLONG_MAX || s2[i]==LLONG_MAX || des[i]==LLONG_MAX)continue;
           ans=min(ans,s1[i]+s2[i]+des[i]);
        }
        return ans==LLONG_MAX?-1:ans;
    }
};