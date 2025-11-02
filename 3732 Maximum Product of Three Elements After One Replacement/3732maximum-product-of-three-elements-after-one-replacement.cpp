class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        int n=nums.size();
        long long k1=1ll*nums[0]*nums[1];
        long long k2=1ll*nums[n-1]*nums[n-2];
        long long k3=1ll*nums[0]*nums[n-1];
        ans=max(ans,k1*1ll*100000);
        ans=max(ans,k2*1ll*100000);
        ans=max(ans,k3*1ll*100000*-1);
        return ans;
    }
};