class Solution {
private :
    int bfs(int x,int y,vector<vector<int>>& grid, vector<vector<int>>&vis){
         int row=grid.size();
        int col=grid[0].size();
        int count=0;
        queue<pair<int,int>>que;
        que.push({x,y});
        int indx[4]={0,0,-1,1};
        int indy[4]={1,-1,0,0};
       while(!que.empty()){
        int x=que.front().first;
        int y=que.front().second;
        count+=grid[x][y];
        que.pop();
        for(int i=0;i<4;i++){
            int nx=x+indx[i];
            int ny=y+indy[i];
            if(nx>=0 && ny>=0 && nx<row && ny<col && vis[nx][ny]==0 && grid[nx][ny]!=0){
                vis[nx][ny]=1;
                que.push({nx,ny});
            }
        }
       }
       return count;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
         int ans=0;
       vector<vector<int>>vis(row,vector<int>(col,0));
       for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]!=0 && vis[i][j]==0){
                vis[i][j]=1;
               ans=max(ans, bfs(i,j,grid,vis));
            }
        }
       }
       return ans;
    }
};