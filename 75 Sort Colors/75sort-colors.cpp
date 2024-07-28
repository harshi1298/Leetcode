class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0=0,count1=0,count2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) count0++;
            if(nums[i]==1) count1++;
            if(nums[i]==2) count2++;
        }
        int i=0;
        while(i<count0) nums[i++]=0;
        while(i<count1+count0) nums[i++]=1;
        while(i<count0+count1+count2) nums[i++]=2;
    }
};