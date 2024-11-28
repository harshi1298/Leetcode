class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>ans(row,vector<int>(col,INT_MAX));
        queue<pair<int,int>>que;
        que.push({0,0});
        ans[0][0]=0;
        while(!que.empty()){
            int x=que.front().first;
            int y=que.front().second;
            que.pop();
            int indx[4]={0,0,1,-1};
            int indy[4]={1,-1,0,0};
            for(int i=0;i<4;i++){
                int nx=indx[i]+x;
                int ny=indy[i]+y;
                if(nx>=0 && ny>=0 && nx<row && ny<col){
                    if(ans[nx][ny]>ans[x][y]+grid[nx][ny]){
                        ans[nx][ny]=ans[x][y]+grid[nx][ny];
                        que.push({nx,ny});
                    }
                }
            }
        }
        return ans[row-1][col-1];
    }
};