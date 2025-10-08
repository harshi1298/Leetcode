class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long pre=0;
        int n=beans.size();
        sort(beans.begin(),beans.end());
        vector<long long>suff(n+1,0);
        for(int i=n-1;i>=0;i--){
            suff[i]=suff[i+1]+1ll*beans[i];
        }
        long long ans=LLONG_MAX;
        for(int i=0;i<n;i++){
           long long t=suff[i+1]-(1ll*beans[i]*(n-i-1))+pre;
           ans=min(ans,t);
           pre+=beans[i];
        }
        return ans;
    }
};