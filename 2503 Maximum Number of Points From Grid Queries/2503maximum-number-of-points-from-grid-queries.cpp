class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pair<int,int>> vec;
        int n=queries.size();
        for(int i=0;i<n;i++){
            vec.push_back(make_pair(queries[i],i));
        }
        int row=grid.size(),col=grid[0].size();
        vector<vector<bool>> vis(row,vector<bool>(col,0));
        sort(vec.begin(),vec.end());
        int i=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> que;
        vector<int> ans(n,0);
        que.push(make_pair(grid[0][0],make_pair(0,0)));
        int sum=0;
        vis[0][0] = true;
        int dx[4]={-1,+1,0,0};
        int dy[4]={0,0,1,-1};
     for(int i=0;i<n;i++){
        auto it=vec[i];
        while(!que.empty()){
            auto f=que.top();
            que.pop();
            int x=f.second.first;
            int y=f.second.second;
            int temp=f.first;
            if(temp>=it.first){
                que.push(f);
                break;
            }
            sum++;
            for(int i=0;i<4;i++){
                int ndx=x+dx[i];
                int ndy=y+dy[i];
                if(ndx>=0 && ndy>=0 && ndx<row && ndy<col && !vis[ndx][ndy]){
                    que.push(make_pair(grid[ndx][ndy],make_pair(ndx,ndy)));
                    vis[ndx][ndy]=1;
                }
            }
        }
        ans[it.second]=sum;
        }
        return ans;
    }
};
