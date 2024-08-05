class Solution {
private:
   int binarysearch(vector<int> nums,int i,int j,int key){
    cout<<i<<" "<<j;
    while(i<=j){
        int mid=i+(j-i)/2;
        if(nums[mid]==key) return mid;
        else if(nums[mid]>key) j=mid-1;
        else i=mid+1;
    }
    return -1;
   }
public:
    bool search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target) return true;
            else if(nums[i]==nums[mid] && nums[mid]==nums[j]) {
                i=i+1;
                j=j -1;
                continue;
            }
            else if(nums[i]<=nums[mid]){
               if(nums[i]<=target && nums[mid]>=target){
                j=mid-1;
               }
               else i=mid+1;
            }
            else{
                if(nums[mid]<=target && nums[j]>=target){
                  i=mid+1;
               }
               else j=mid-1;
            }
        }
        return false;
    }
};