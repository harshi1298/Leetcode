class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        long long ans=0;
        int n=h.size();
        sort(h.begin(),h.end(),greater<int>());
        for(int i=0;i<min(n,k);i++){
            ans+=1ll*max(0,h[i]-i);
        }
        return ans;
    }
};