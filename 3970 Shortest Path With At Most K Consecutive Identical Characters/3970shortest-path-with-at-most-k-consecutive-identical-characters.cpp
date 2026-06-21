class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string label, int k) {
        priority_queue<tuple<int,int,char,int>,vector<tuple<int,int,char,int>>,greater<tuple<int,int,char,int>>> pq;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        pq.push(make_tuple(0,0,label[0],1));
        vector<vector<int>>dis(n+1,vector<int>(k+2,INT_MAX));
        while(!pq.empty()){
            auto [wt,i,ch,count]=pq.top();
            pq.pop();
            if(i==n-1)return wt;
            for(auto [it,nw] : adj[i]){
                if(ch==label[it] && count==k)continue;
                int nk=ch==label[it]?count+1:1;
                if(dis[it][nk]>wt+nw){
                    dis[it][nk]=wt+nw;
                    pq.push(make_tuple(wt+nw,it,label[it],nk));
                }
            }
        }
        return -1;
    }
};