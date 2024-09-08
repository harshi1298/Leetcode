class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        if(nums.size()==1)return 0;
        long long  maxi=nums[0];
        long long  maxindex=0;
        long long ans=0;
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>maxi){
                ans=ans+(i-maxindex)*maxi;
                maxi=nums[i];
                maxindex=i;
            }
        }
        ans=ans+nums[maxindex]*((nums.size()-1-maxindex));
        return ans;
    }
};