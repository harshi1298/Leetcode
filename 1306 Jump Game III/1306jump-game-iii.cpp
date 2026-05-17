class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int>vis(n,0);
        queue<int>que;
        que.push(start);
        while(!que.empty()){
            auto k=que.front();
            if(arr[k]==0)return true;
            que.pop();
            int nc=k-arr[k];
            int pc=k+arr[k];
            if(nc>=0 && !vis[nc]){
                que.push(nc);
                vis[nc]=1;
            }
            if(pc<n && !vis[pc]){
                que.push(pc);
                vis[pc]=1;
            }
        }
        return false;
    }
};