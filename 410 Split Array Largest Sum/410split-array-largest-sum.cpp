class Solution {
private:
    bool ispossible(int mid,vector<int>&nums,int k){
        int j=0,i;
        for( i=0;i<k;i++){
            int temp=mid;
            while(j<nums.size() && temp-nums[j]>=0){
                temp-=nums[j];
                j++;
            }
        }
        if(j==nums.size())return true;
        return false;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int j =accumulate(nums.begin(),nums.end(),0);
        int i=0,ans=-1;
        while(i<=j){
            int mid=(j-i)/2+i;
            if(ispossible(mid,nums,k)){
               ans=mid;
               j=mid-1;
            }
            else i=mid+1;
        }
        return ans;
    }
};