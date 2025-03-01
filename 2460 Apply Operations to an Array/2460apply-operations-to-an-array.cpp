class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int l=nums.size();
        int i=0;
        while(i<l-1){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
            i++;
        }
        int n=nums.size();
        int j=0;
        i=0;
        while(j<l && i<l){
            if(nums[i]!=0) i++;
            else{
                if(nums[j]!=0 && i<j) swap(nums[j],nums[i]);
                j++;
            }
        }
       return nums;
    }
};