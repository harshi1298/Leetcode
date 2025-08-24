class Solution {
private:
    long long ans=0;
    unordered_map<long long ,int>mapp;
    int dfs(vector<vector<int>>&adj,vector<int>&vis,int i,int par){
        int sum=1;
        long long prod=1;
        vis[i]=1;
        for(auto it : adj[i]){
            if(it==par)continue;
            if(!vis[it]){
                int count=dfs(adj,vis,it,i);
                prod*=1ll*count;
                sum+=count;
            }
        }
        if(i!=0)
            prod*=(1ll*adj.size()-sum);
        mapp[prod]++;
        ans=max(ans,prod);
        return sum;
    }
public:
    int countHighestScoreNodes(vector<int>& par) {
        int n=par.size();
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
            adj[par[i]].push_back(i);
        }
        vector<int>vis(n,0);
        dfs(adj,vis,0,-1);
        return mapp[ans];
    }
};