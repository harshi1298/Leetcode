class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        int n=values.size();
        int m=values[0].size();
        long long ans=0;
        for(int i=0;i<n;i++)pq.push(make_tuple(values[i][m-1],i,m-1));
        int d=1;
        while(!pq.empty()){
             auto [val,r,c]=pq.top();
             pq.pop();
             ans+=1ll*val*d;
             if(c-1>=0)pq.push(make_tuple(values[r][c-1],r,c-1));
             d++;
        }
        return ans;
    }
};  