class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini=nums[0];
        int i=0,j=nums.size()-1;
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[i]<=nums[mid]){
                mini=min(nums[i],mini);
                i=mid+1;
            }
            else{
                mini=min(mini,nums[mid]);
                j=mid-1;
            }
        }
        return mini;
    }
};