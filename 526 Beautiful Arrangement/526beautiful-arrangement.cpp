class Solution {
private:
    int ans=0;
    void solve(int n,vector<int>&vis,int idx){
        if(idx>n){
            ans++;
            return ;
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(i%idx==0 || idx%i==0){
                    vis[i]=1;
                    solve(n,vis,idx+1);
                    vis[i]=0;
                }
            }
        }
    }
public:
    int countArrangement(int n) {
        vector<int>vis(n+1,0);
        solve(n,vis,1);
        return ans;
    }
};