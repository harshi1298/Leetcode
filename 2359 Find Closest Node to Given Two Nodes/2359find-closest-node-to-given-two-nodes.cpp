class Solution {
private:
     void bfs(vector<vector<int>>&adj,vector<int>&dis,int node){
        queue<int>que;
        que.push(node);
        dis[node]=0;
        int time=0;
        while(!que.empty()){
            int k=que.size();
            time++;
            for(int i=0;i<k;i++){
                int tp=que.front();
                que.pop();
                for(auto it: adj[tp]){
                    if(dis[it]==-1){
                        dis[it]=time;
                        que.push(it);
                    }
                }
            }
        }
     }
    //  void print(vector<int>s){
    //     for(auto it : s)cout<<it<<" ";
    //     cout<<endl;
    //  }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>dis1(n,-1),dis2(n,-1);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
              adj[i].push_back(edges[i]);
            }
        }
        // for(int i=0;i<n;i++){
        //     for(auto it : adj[i])cout<<it<<" ";
        //     cout<<endl;
        // }
        bfs(adj,dis1,node1);
        bfs(adj,dis2,node2);
        int mini=INT_MAX,ans=node1;
        for(int i=0;i<n;i++){
            if(dis1[i]!=-1 && dis2[i]!=-1){
                if(max(dis1[i],dis2[i])<mini){
                    mini=max(dis1[i],dis2[i]);
                    ans=i;
                }
            }
        }
        // print(dis1);
        // print(dis2);  
        return mini==INT_MAX?-1:ans;
    }
};