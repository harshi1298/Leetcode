class Solution {
private:
    int modulo=1e9+7;
    int solve(vector<vector<pair<int,int>>>&graph,int t,int s,int n,vector<vector<int>>&dp){
        if(s==n)return 1;
        if(dp[s][t]!=-1)return dp[s][t];
        int count=0;
        for(auto j:graph[s]){
            if(t-j.second>=0){
                count=(count+solve(graph,t-j.second,j.first,n,dp))%modulo;
            }
        }
        return dp[s][t]=count;
    }
public:
    int countPaths(int n, vector<vector<int>>& t) {
        vector<vector<pair<int,int>>>graph(n);
        for(int i=0;i<t.size();i++){
            graph[t[i][0]].push_back({t[i][1],t[i][2]});
            graph[t[i][1]].push_back({t[i][0],t[i][2]});
        }
        vector<long long>ans(n,LLONG_MAX);
        vector<long long >count(n,0);
        count[0]=1;
       priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
       pq.push({0,0});
       ans[0]=0;
       while(!pq.empty()){ 
           auto l=pq.top();
           pq.pop();
           int parent=l.second;
          long long pweight=l.first;
           for(auto j :graph[parent]){
               if(ans[j.first]>(j.second)+pweight){
                 ans[j.first]=j.second+pweight;
                 pq.push({ans[j.first],j.first});
                 count[j.first]=count[parent];
               }
               else if(ans[j.first]==j.second+pweight){
                count[j.first]=((count[j.first])+(count[parent]))%modulo;
               }
           }
       } 
    //    vector<vector<int>>dp(n,vector<int>(ans[n-1]+1,-1));
    //    return solve(graph,ans[n-1],0,n-1,dp);
    return count[n-1];
    }
};