class Solution {
public:
    int networkDelayTime(vector<vector<int>>& t, int n, int k) {
        vector<int>ans(n,INT_MAX);
        vector<vector<pair<int,int>>>graph(n);
        for(int i=0;i<t.size();i++){
            graph[t[i][0]-1].push_back({t[i][1]-1,t[i][2]});
        }
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       pq.push({0,k-1});
       ans[k-1]=0;
       while(!pq.empty()){ 
           auto l=pq.top();
           pq.pop();
           int parent=l.second;
           int pweight=l.first;
           for(auto j :graph[parent]){
               if(ans[j.first]>j.second+pweight){
                 ans[j.first]=j.second+pweight;
                 pq.push({ans[j.first],j.first});
               }
           }
       }
       int a=INT_MIN;
       for(auto j: ans){
        a=max(a,j);
       }
       return a==INT_MAX?-1:a;
    }
};