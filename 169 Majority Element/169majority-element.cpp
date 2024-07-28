class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int max_freq=0;
        int max_val;
        for(auto v: m){
            if(v.second>max_freq){
                max_freq=v.second;
                max_val=v.first;
            }
        }
        return max_val;
    }
};