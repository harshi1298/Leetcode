class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        if(j==0)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[j]>nums[j-1])return j;
        i++;j--;
        while(i<=j){
            int mid=(j-i)/2+i;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])return mid;
            else if(nums[mid]>nums[mid-1])i=mid+1;
            else j=mid-1;
        }
        return -1;
    }
};