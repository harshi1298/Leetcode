class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums[0]>target) return 0;
        if(nums[nums.size()-1]<target) return nums.size();
         int i=0,j=nums.size()-1;
         int ans;
         int mid=i+(j-i)/2;
         while(i<=j){
            mid=i+(j-i)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                 ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
                 
            }
         }
         return ans;
    }
};