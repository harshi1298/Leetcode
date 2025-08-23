class Solution {
public:
    vector<long long> countBlackBlocks(int n, int m, vector<vector<int>>& cd) {
        vector<long long>ans(5,0);
        map<pair<int,int>,int>st;
        int idx[4]={0,0,-1,-1};
        int idy[4]={0,-1,0,-1};
        for(auto it : cd){
            int nx=it[0],ny=it[1];
           for(int i=0;i<4;i++){
                int x=nx+idx[i],y=ny+idy[i];
                if(x>=0 && y>=0 && x<n-1 && y<m-1){
                    st[{x,y}]++;
                }
            }
        }
        for(auto [_,p]: st)ans[p]++;
        long long total=accumulate(ans.begin(),ans.end(),0);
        ans[0]=((1ll*(m-1)*(n-1))-total);
        return ans;
    }
};