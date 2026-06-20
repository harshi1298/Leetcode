class Solution {
private:
    
    long long  dfs(vector<int>&bt,int i,int p,vector<vector<int>>&adj){
        long long mini=LLONG_MAX,maxi=LLONG_MIN;
        int ch=0;
        for(auto it : adj[i]){
            if(it !=p){
                long long temp=dfs(bt,it,i,adj);
                mini=min(mini,temp);
                maxi=max(maxi,temp);
                ch++;
                
            }
        }
        if(ch==0){
            return bt[i];
        }
        return 2*maxi+1ll*bt[i]-mini;
         
    }
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>>adj(n);
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(baseTime,0,-1,adj);
        
    }
};