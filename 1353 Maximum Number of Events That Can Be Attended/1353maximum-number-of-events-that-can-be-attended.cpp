class Solution {
public:
    int maxEvents(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        int n=nums.size(),ans=0,day=0;
        for(int i=0;i<n || !(pq.empty());){
            if(pq.empty()){
                day=nums[i][0];
            }
            while(i<n && nums[i][0]<=day){
                pq.push(nums[i][1]);
                i++;
            }
            while(!pq.empty() && pq.top()<day)pq.pop();
            if(!pq.empty()){
                pq.pop();
                ans++;
                day++;
            }
        }
        return ans;
    }
};