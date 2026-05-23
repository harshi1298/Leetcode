class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>>mapp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mapp[arr[i]].push_back(i);
        }
        queue<pair<int,int>>que;
        vector<int>vis(n,0);
        que.push({0,0});
        while(!que.empty()){
            auto [dist,val]=que.front();
            que.pop();
            
            if(val==n-1)return dist;
            if(val-1>=0 && vis[val-1]==0){
                que.push({dist+1,val-1});
                vis[val-1]=1;
            }
            if(val+1<n && vis[val+1]==0){
                que.push({dist+1,val+1});
                vis[val+1]=1;
            }
            for(auto it : mapp[arr[val]]){
                if(vis[it]==0)
                que.push({dist+1,it});
                vis[it]=1;
            }
            mapp[arr[val]].clear();
        }
        return -1;
    }
};