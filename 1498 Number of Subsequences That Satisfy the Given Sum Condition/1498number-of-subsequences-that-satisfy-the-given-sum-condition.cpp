class Solution {
int mod=1e9+7;
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>power(n+1,1);
        for(int i=1;i<=n;i++)power[i]=(2*power[i-1])%mod;
        int i=0,j=n-1;
        long long ans=0;
        while(i<=j){
            if(nums[i]+nums[j]>target)j--;
            else{
                ans+=power[j-i];
                ans%=mod;
                i++;
            }
        }
        return ans;
    }
};