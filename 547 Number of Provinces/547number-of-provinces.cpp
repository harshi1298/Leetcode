class Solution {
private:
    void solve(vector<vector<int>>& adj,int i,vector<int>&vis){
       vis[i]=1;
       for(int j=0;j<adj.size();j++){
        if(!vis[j] && adj[i][j] ){
            solve(adj,j,vis);
        }
       }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>vis(isConnected.size());
        int count=0;
         for (int i = 0; i < isConnected.size(); i++) {
            if(!vis[i]){
                solve(isConnected,i,vis);
                count++;
            }
        }
        return count;
    }
};
