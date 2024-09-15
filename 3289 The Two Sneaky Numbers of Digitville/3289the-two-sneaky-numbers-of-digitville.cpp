class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int k=nums.size();
        vector<int>ans;
        unordered_map<int,bool>mapp;
        for(int i=0;i<k;i++){
            if(mapp[nums[i]]){
                ans.push_back(nums[i]);
            }
            mapp[nums[i]]=true;
        }
        return ans;
    }
};