class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>>que;
        vector<vector<int>>ans(row,vector<int>(col,INT_MAX));
        if(grid[0][0]==0){
        ans[0][0]=1;
        que.push({0,0});}
        while(!que.empty()){
            int x=que.front().first;
            int y=que.front().second;
            que.pop();
            int indx[8]={-1,1,0,0,-1,1,1,-1};
            int indy[8]={0,0,-1,1,-1,1,-1,1};
            for(int i=0;i<8;i++){
                int nx=x+indx[i];
                int ny=indy[i]+y;
                if(nx>=0 && ny>=0 && nx<row && ny<col && grid[nx][ny]==0 && ans[x][y]+1<ans[nx][ny]){
                    ans[nx][ny]=ans[x][y]+1;
                    que.push({nx,ny});
                }
            }
        }
        return ans[row-1][col-1]==INT_MAX?-1:ans[row-1][col-1];
    }
};