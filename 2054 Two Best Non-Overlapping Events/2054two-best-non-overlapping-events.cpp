class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& e) {
        sort(e.begin(),e.end());
        int n=e.size();
        vector<int>smax(n);
        smax[n-1]=e[n-1][2];
        for(int i=n-2;i>=0;i--){
           smax[i]=max(e[i][2],smax[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            auto it=upper_bound(e.begin()+i,e.end(),vector<int>({e[i][1],INT_MAX,INT_MAX}));
            if(it==e.end())ans=max(ans,e[i][2]);
            else ans=max(ans,e[i][2]+smax[it-e.begin()]);
        }
        return ans;
    }
};