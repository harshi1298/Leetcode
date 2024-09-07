class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mapp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            mapp[nums[i]]=mapp[nums[i]]+1;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it: mapp){
            pq.push({it.second,it.first});
        }
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};