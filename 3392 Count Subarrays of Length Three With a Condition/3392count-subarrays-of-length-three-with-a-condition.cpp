class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i=0,j=1,k=2;
        int ans=0;
        while(k<nums.size()){
;          if(nums[j]%2==0 && (nums[j]/2)==(nums[i]+nums[k])){
            ans++;
          }
          i++;j++;k++;
        }
        return ans;
    }
};