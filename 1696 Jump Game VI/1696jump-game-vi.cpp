class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        pq.push({nums[0],0});
        int n=nums.size();
        for(int i=1;i<n;i++){
            while(pq.top().second<i-k)pq.pop();
            pq.push({pq.top().first+nums[i],i});
        }
        while(pq.top().second!=n-1)pq.pop();
        return pq.top().first;
    }
};