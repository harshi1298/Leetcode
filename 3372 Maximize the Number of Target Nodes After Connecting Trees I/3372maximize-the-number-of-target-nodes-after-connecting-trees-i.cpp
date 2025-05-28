class Solution {
private:
    int dfs(vector<vector<int>>&adj,int i,int parent,int dis,int k){
        if(dis>k)return 0;
        if(dis==k)return 1;
        int sum=1;
        for(auto it: adj[i]){
            if(it!=parent){
                sum+=dfs(adj,it,i,dis+1,k);
            }
        }
        return sum;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size()+1,m=edges2.size()+1;
        vector<vector<int>>adj1(n);
        vector<vector<int>>adj2(m);
        for(auto it: edges1){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        for(auto it :edges2){
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }
        vector<int>dp1(n);
        vector<int>dp2(m);
        for(int i=0;i<n;i++){
           dp1[i]=dfs(adj1,i,-1,0,k);
        }
        for(int i=0;i<m;i++){
           dp2[i]=dfs(adj2,i,-1,0,k-1);
        } 
        int maxi=0;
        for(int i=0;i<m;i++){
            maxi=max(maxi,dp2[i]);
        }
        vector<int>ans(n); 
        for(int i=0;i<n;i++){
            ans[i]=maxi+dp1[i];
        }
        return ans;
    }
}; 