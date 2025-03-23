class Solution {
private:
    void dfs(vector<int>&vis,vector<vector<int>>&adj,int i){
        for(auto it:adj[i]){
            if(!vis[it]){
                vis[it]=1;
                dfs(vis,adj,it);
            }
        }
    }
public:
    int numberOfComponents(vector<vector<int>>& p, int k) {
        int r=p.size();
        int c=p[0].size();
        vector<vector<int>>adj(r);
        for(int i=0;i<r;i++)sort(p[i].begin(),p[i].end());
        for(int i=0;i<r;i++){
            unordered_set<int>st;
            for(int j=0;j<c;j++){
                st.insert(p[i][j]);
            }
            for(int j=i+1;j<r;j++){
                int temp=0;
               for(int k=0;k<c;k++){
                   if(k>0 && p[j][k]==p[j][k-1])continue;
                   if(st.find(p[j][k])!=st.end()){
                       temp++;
                   }
               }
               if(temp>=k){
                   adj[i].push_back(j);
                   adj[j].push_back(i);
               }
            }
        }
        vector<int>vis(r,0);
        int ans=0;
        for(int i=0;i<r;i++){
            if(!vis[i]){
                dfs(vis,adj,i);
                ans++;
            }
        }
        return ans;
    }
};