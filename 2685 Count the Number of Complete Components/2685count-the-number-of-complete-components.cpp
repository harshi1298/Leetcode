class Solution {
private:
    bool flag=true;
    void dfs(vector<vector<int>>&adj,vector<int>&vis,int i,int &c){
        for(auto &it :adj[i]){
           if(!vis[it]){
            vis[it]=1;
            c++;
            dfs(adj,vis,it,c);
           }
        }
        if(adj[i].size()!=c-1)flag=false;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &it :edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
           if(!vis[i]){
            int c=0;
            if(adj[i].size()!=0)
            dfs(adj,vis,i,c);
            if(flag)ans++;
            cout<<ans<<" "<<i<<endl;
            flag=true;
           }
        }
        return ans;
    }
};