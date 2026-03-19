class Solution {
private:
    vector<int>solve(int k, vector<vector<int>>& rc){
        vector<vector<int>>adj(k);
        vector<int>indegree(k,0);
        for(auto it : rc){
            adj[it[0]-1].push_back(it[1]-1);
            indegree[it[1]-1]++;
        }
        queue<int>que;
        for(int i=0;i<k;i++){
            if(indegree[i]==0)que.push(i);
        }
        vector<int>topo;
        while(!que.empty()){
            int tp=que.front();
            que.pop();
            topo.push_back(tp);
            for(auto it : adj[tp]){
                indegree[it]--;
                if (indegree[it] == 0)
                    que.push(it);
            }
        }
        if(topo.size()<k)return {};
        return topo;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
       vector<int>arr1=solve(k,rc);
       vector<int>arr2=solve(k,cc);
        if(arr1.size()==0 || arr2.size()==0){
            return {};
        }
        unordered_map<int,pair<int,int>>mapp;
        for(int i=0;i<k;i++){
            cout<<arr1[i]<<" ";
            mapp[arr1[i]+1].first=i;
        }
        for(int i=0;i<k;i++){
            mapp[arr2[i]+1].second=i;
        }
        vector<vector<int>>ans(k,vector<int>(k,0));
        for(auto [key,val]: mapp){
            ans[val.first][val.second]=key;
        }
        return ans;
    }
};