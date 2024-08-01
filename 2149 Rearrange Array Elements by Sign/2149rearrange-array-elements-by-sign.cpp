class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i1=0,i2=1;
        vector<int>ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans[i1]=nums[i];
                i1+=2;
            }
            else{
                ans[i2]=nums[i];
                i2+=2;
            }
        }
        return ans;;
    }
};