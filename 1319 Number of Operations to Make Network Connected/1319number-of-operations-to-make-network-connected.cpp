class Solution {
private:
    void dfs(vector<vector<int>>&adj,int i, vector<int>&vis){
        vis[i]=1;
        for(auto j:adj[i]){
            if(!vis[j])dfs(adj,j,vis);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& c) {
        if(c.size()<n-1)return -1;
        int count=0;
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(auto j:c){
            adj[j[0]].push_back(j[1]);
            adj[j[1]].push_back(j[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis);
                count++;
            }
        }
        return count-1;
    }
};