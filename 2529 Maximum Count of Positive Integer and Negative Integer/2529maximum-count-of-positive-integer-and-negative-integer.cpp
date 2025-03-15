class Solution {
public:
    int maximumCount(vector<int>& nums) {
       int k=lower_bound(nums.begin(),nums.end(),0)-nums.begin();
       int l=nums.end()- upper_bound(nums.begin(),nums.end(),0);
       return max(k,l);
    }
};