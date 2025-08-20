class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int>mapp;
        for(auto it : nums)mapp[it]++;
        for(auto it : mapp)if(it.second>2)return false;
        return true;;
    }
};