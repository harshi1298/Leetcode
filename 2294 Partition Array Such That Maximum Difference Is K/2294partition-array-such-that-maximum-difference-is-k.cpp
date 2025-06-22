class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,n=nums.size();
        int ans=0;
        while(i<n){
           ans++;
           i=upper_bound(nums.begin(),nums.end(),nums[i]+k)-nums.begin();
        }
        return ans;
    }
};