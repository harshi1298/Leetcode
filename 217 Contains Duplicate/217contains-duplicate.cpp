class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int k=nums.size();
        int l=1;
        for(int i=0;i<k-1;i++){
            if(nums[i]==nums[i+1])
            { l++;
            break;}
             else
             l=1;
        }
        if(l>1)
         return 1;
        else return 0;
    }
};