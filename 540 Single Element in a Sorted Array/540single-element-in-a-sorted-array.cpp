class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i=1,j=nums.size()-1;
        if(j==0)return nums[0];
        if(nums[j]!=nums[j-1]) return nums[j];
        if(nums[0]!=nums[1]) return nums[0];
        j--;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            if((mid%2==0 && nums[mid]==nums[mid+1])|| (mid%2==1 &&  nums[mid]!=nums[mid+1])){
                 i=mid+1;
            }
            else j=mid-1;
        }
        return -1;
    }
};