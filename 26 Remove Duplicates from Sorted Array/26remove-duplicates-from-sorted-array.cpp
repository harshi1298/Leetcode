class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=nums.size();
        int j=0;
        for(int i=0;i<l;i++){
            if(i+1<l){
            if(nums[j]!=nums[i+1]){
                nums[j+1]=nums[i+1];
                j++;
            }}
            else
             j++;
        }
        return j;
    }
};