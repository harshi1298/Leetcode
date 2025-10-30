#define tp tuple<int,int,int>
class Solution {
public:
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& pt) {
        vector<tp>arr;
        int n=st.size();
        for(int i=0;i<n;i++){
            arr.push_back(make_tuple(st[i],pt[i],et[i]));
        }
        sort(arr.begin(),arr.end());
        vector<int>dp(n,0);
        auto [k,l,m]=arr[n-1];
        dp[n-1]=l;
        for(int i=n-2;i>=0;i--){
           auto [s,p,e]=arr[i];
           auto it =lower_bound(arr.begin(),arr.end(),make_tuple(e,0,0));
           if(it==arr.end()){
            dp[i]=max(p,dp[i+1]);
           }
           else 
            dp[i]=max(dp[i+1],p+dp[(int)(it-arr.begin())]);
        }
        return dp[0];
    }
};