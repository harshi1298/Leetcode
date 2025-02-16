class Solution {
private:
    bool solve(int i,vector<int>&ans,vector<int>& vis,int n){
       if(i>=ans.size())return true;
       if(ans[i]!=-1)return solve(i+1,ans,vis,n);
       for(int j=n;j>=1;j--){
        if(vis[j]==1)continue;
        vis[j]=1;
        ans[i]=j;
        if(j==1){
          if(solve(i+1,ans,vis,n))return true;
        }
        else if(i+j<ans.size() && ans[i+j]==-1){
            ans[i+j]=j;
            if(solve(i+1,ans,vis,n)){
                return true;
            }
            ans[i+j]=-1;
        }
        vis[j]=0;
        ans[i]=-1;
       }
       return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int>ans(2*n-1,-1);
        vector<int>vis(n+1,0);
        solve(0,ans,vis,n);
        return ans;
    }
};