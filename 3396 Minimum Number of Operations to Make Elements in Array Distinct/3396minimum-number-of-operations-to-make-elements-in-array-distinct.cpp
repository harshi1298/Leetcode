class Solution {
public:
    int minimumOperations(vector<int>& nums) {
      unordered_map<int,int>mapp;
      int  rem=-1;
      for(int i=0;i<nums.size();i++){
        if(mapp.find(nums[i])!=mapp.end())rem=max(mapp[nums[i]],rem);
         mapp[nums[i]]=i;
      } 
      if(rem==-1)return 0;
      return rem/3+1; 
    }
};