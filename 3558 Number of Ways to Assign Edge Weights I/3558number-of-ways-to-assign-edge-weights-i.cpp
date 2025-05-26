class Solution {
private:
int dfs(vector<vector<int>>& adj,vector<int>&vis,int i){
        vis[i]=1;
        int temp=0;
        for(auto it :adj[i]){
            if(!vis[it]){
                temp=max(temp,1+dfs(adj,vis,it));
            }
        }
       return temp;
    }
const int mod = 1e9 + 7;
int power(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a % mod;

    if (b % 2 == 1) {
        return (1LL * a * power(a, b - 1)) % mod;
    }

    int half = power(a, b / 2);
    return (1LL * half * half) % mod;
}
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>vis(n+2,0);
        vector<vector<int>>adj(n+2);
        for(auto it :edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int total=dfs(adj,vis,1);
        if(total==0)return 1;
        return power(2,total-1);
    }
};