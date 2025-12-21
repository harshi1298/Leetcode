class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int>>mapp;
        for(auto it : nums){
           mapp[it%3].push(it);
        }
        int ans=0;
        int maxi0=mapp[0].empty()?-3e5:mapp[0].top(),maxi1=mapp[1].empty()?-3e5:mapp[1].top(),maxi2=mapp[2].empty()?-3e5:mapp[2].top();
        for(int i=0;i<3;i++){
            int count=0;
            if(mapp[i].size()>=3){
               auto pq=mapp[i];
               count+=pq.top();
               pq.pop();
               count+=pq.top();
               pq.pop();
               count+=pq.top();
            }
            ans=max(ans,count);
        }
        ans=max(ans,maxi0+maxi1+maxi2);
        return ans;
    }
};