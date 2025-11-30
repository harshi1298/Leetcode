class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        if(nums.size()==1){
            return 1;
        }
        if(k==0)return nums.size();
        sort(nums.begin(),nums.end());
        int i=nums.size()-k;
        while(i>0){
           if(nums[i]>nums[i-1])return i;
           i--;
        }
        return 0;
    }
};