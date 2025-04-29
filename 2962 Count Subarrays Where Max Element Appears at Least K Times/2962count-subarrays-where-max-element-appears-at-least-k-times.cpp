class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long l=0,maxi=*max_element(nums.begin(),nums.end()),n=nums.size(),count=0;
        long long ans=0;
        for(int r=0;r<n;r++){
           count+=(nums[r]==maxi);
           while(count>=k){
            if(nums[l]==maxi)count--;
            l++;
           }
           ans+=(r-l+1);
        }
        return n*(n+1)/2-ans;
    }
};