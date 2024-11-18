class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>>vis(row,vector<int>(col,0));
        queue<pair<pair<int,int>,int>>que;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
               if(mat[i][j]==0){
                 que.push({{i,j},0});
                 vis[i][j]=1;
               }
            }
        }
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        vector<vector<int>>ans(row,vector<int>(col,0));
        while(!que.empty()){
            int r=que.front().first.first;
            int c=que.front().first.second;
            int s=que.front().second;
            que.pop();
            for(int i=0;i<4;i++){
                int nx=r+dx[i],ny=c+dy[i];
                if(nx>=0 && nx<row && ny>=0 && ny<col && !vis[nx][ny]){
                   vis[nx][ny]=1;
                   ans[nx][ny]=s+1;
                   que.push({{nx,ny},s+1});
                }
            }
        }
        return ans;
    }
};