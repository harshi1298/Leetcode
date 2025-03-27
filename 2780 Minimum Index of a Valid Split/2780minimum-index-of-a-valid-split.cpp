class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> mapp;
        unordered_map<int,int> map2;
        int n=nums.size();
        for(auto &it:nums) mapp[it]++;
        for(int i=0;i<n;i++){
            map2[nums[i]]++;
            if(map2[nums[i]]*2>i+1 && (mapp[nums[i]]-map2[nums[i]])*2>n-i-1) return i;
        }
        return -1;
    }
};