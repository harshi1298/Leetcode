class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> h;
        for(int i=0;i<nums.size();i++){
            h[nums[i]]++;
        }
        vector<int>ans;
        for(auto i: h){
           if((i.second)>(nums.size()/3))
             ans.push_back(i.first);
        }
        return ans;
    }
};