class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>temp=nums;
        int t=k;
        for(int i=0;i<n-1;i++){
            if(nums[i]==-1){
                nums[i+1]*=(-1);
                k--;
            }
        }
        if(k>=0 && nums[n-1]==1)return true;
        k=t;
        nums=temp;
         for(int i=0;i<n-1;i++){
            if(nums[i]==1){
                nums[i+1]*=(-1);
                k--;
            }
        }
         if(k>=0 && nums[n-1]==-1)return true;
        return false;
    }
};