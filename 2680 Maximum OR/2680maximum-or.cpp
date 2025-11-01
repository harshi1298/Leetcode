class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pre(n+1),suff(n+1);
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]|nums[i-1];
        }
        for(int i=n-1;i>=0;i--){
            suff[i]=suff[i+1] |nums[i];
        }

        long long ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,((1ll*nums[i])<<k) | suff[i+1] | pre[i]);
        }
        return ans;
    }
};