class Solution {
private:
    bool dfs(vector<vector<pair<int,int>>>&adj,int st,int tar,int k,int mid,vector<int>&vis){
        if(k<0)return false;
        if(st==tar)return true;
        for(auto &it : adj[st]){
            int v=it.first,w=it.second;
            if(!vis[v]){
                vis[v]=1;
                if(w>mid){
                    if(dfs(adj,v,tar,k-1,mid,vis))return true;
                }
                else{
                     if(dfs(adj,v,tar,k,mid,vis))return true;
                }
            }
        }
        return false;
    }
    bool ispossible(vector<vector<pair<int,int>>>&adj,int st,int tar,int k,int mid){
        vector<int>vis(adj.size(),-1);
        priority_queue<pair<int,int>>pq;
        pq.push({k,st});
        while(!pq.empty()){
            auto [l,v]=pq.top();
            pq.pop();
            if(l<0)continue;
            if(v==tar)return true;
            for(auto [u,w] : adj[v]){
                int newl=l-(w>mid?1:0);
                if(vis[u]<newl){
                    pq.push({newl,u});
                    vis[u]=newl;
                }
            }
        }
        return false;
    }
public:
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        int st=0,end=1e9;
        int ans=-1;
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it : edges){
            int u=it[0],v=it[1],w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        while(st<=end){
            int mid=st+(end-st)/2;
            if(ispossible(adj,source,target,k,mid)){
                ans=mid;
                end=mid-1;
            }
            else st=mid+1;
        }
        return ans;
    }
};