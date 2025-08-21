#define pr pair<int,int>
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        vector<int>vis(n+1,0);
        long long ans=0;
        priority_queue<pr,vector<pr>,greater<pr>>pq;
        for(int i=0;i<n;i++){
            pq.push(make_pair(nums[i],i));
        }
        while(!pq.empty()){
            auto [val,idx]=pq.top();
            pq.pop();
            if(!vis[idx]){
                ans+=val;
                if(idx>0)vis[idx-1]=1;
                if(idx<n-1)vis[idx+1]=1;
                vis[idx]=1;
            }
        }
        return ans;
    }
};