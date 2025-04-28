class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0;
        int l=0,n=nums.size();
        long long sum=0;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            while(sum*(j-l+1)>=k){
                sum-=nums[l];
                l++;
            }
            ans+=(j-l+1);
        }
        return ans;
    }
};