class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        if(k==0)return 0;
        int l=0,n=nums.size();
        long long  sum=1;
        for(int j=0;j<n;j++){
            sum*=nums[j];
            while(l<=j && sum>=k){
                sum/=nums[l];
                l++;
            }
            ans+=(j-l+1);
        }
        return ans;
    }
};