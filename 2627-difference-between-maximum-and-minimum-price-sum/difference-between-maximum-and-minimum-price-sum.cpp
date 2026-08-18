class Solution {
public:
    vector<long long >up,down;
    vector<vector<int>>adj;
    void dfs1(int i,int p,vector<int>&prices){
        long long maxi=prices[i];
        bool leaf=true;
         for(auto it : adj[i]){
            if(it !=p){
              dfs1(it,i,prices);
              maxi=max(maxi,1ll*prices[i]+down[it]);
            }
         }
        down[i]=maxi;
        return ;
    }
    void dfs2(int i,int p,vector<int>&prices){
        long long maxi1=0,maxi2=0,bs=-1;
        for(int it : adj[i]){
            if(it!=p){
                long long val=down[it];
              if(val>maxi1){
                maxi2=maxi1;
                maxi1=val;
                bs=it;
              }
              else if(val>maxi2)maxi2=val;
            }
        }
        for(auto it : adj[i]){
            if(it!=p){
                long long temp=it==bs?maxi2:maxi1;
                temp=bs==-1?0:temp;
                up[it]=prices[it]+max({prices[i]+temp,up[i]});
                dfs2(it,i,prices);
            }
        }
        return ;
    }
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        adj.resize(n+1);
        up.resize(n+1,0);
        down.resize(n+1,0);
        for(auto it : edges){
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs1(0,-1,price);
        dfs2(0,-1,price);
        long long ans=0;
        for(int i=0;i<n;i++){
            cout<<up[i]<<" "<<down[i]<<endl;
        }
        for(int i=0;i<n;i++)ans=max(ans,max(up[i],down[i])-price[i]);
        return ans;

    }
};