class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int k=nums.size();
        vector<int>ans;
        for(int i=0;i<k;i++){
            for(int j=i+1;j<k;j++){
                if(nums[i]+nums[j]==target){
                  ans.push_back(i);
                   ans.push_back(j);
                   break;
                }
            }

           
        }
        return ans;
    }
};