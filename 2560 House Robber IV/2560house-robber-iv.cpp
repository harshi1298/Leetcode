class Solution {
private:
   bool isvalid(vector<int>&nums,int mid,int k){
    int count=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<=mid){
          count++;
          i++;
        }
    }
    if(count>=k)return true;
    return false;
   }
public:
    int minCapability(vector<int>& nums, int k) {
        int mini=1,ans;
      int maxi=*max_element(nums.begin(),nums.end());
      while(mini<=maxi){
        int mid=mini+(maxi-mini)/2;
        if(isvalid(nums,mid,k)){
            maxi=mid-1;
            ans=mid;
        }
        else mini=mid+1;
      }
      return ans;
    }
};