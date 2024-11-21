class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int count=0;
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>>que;
        for(int i=0;i<row;i++){
            if(grid[i][0]==1){que.push({i,0});grid[i][0]=0;};
        }
        for(int i=0;i<col;i++){
            if(grid[0][i]==1){que.push({0,i});grid[0][i]=0;};
        }
        for(int i=0;i<row;i++){
            if(grid[i][col-1]==1){que.push({i,col-1});grid[i][col-1]=0;}
        }
        for(int i=0;i<col;i++){
            if(grid[row-1][i]==1){que.push({row-1,i});grid[row-1][i]=0;}
        }
        while(!que.empty()){
            int x=que.front().first;
            int y=que.front().second;
            que.pop();
            int indx[4]={0,0,-1,1};
            int indy[4]={1,-1,0,0};
            for(int i=0;i<4;i++){
                int nx=indx[i]+x;
                int ny=indy[i]+y;
                if(nx>=0 && ny>=0 && nx<row && ny<col && grid[nx][ny]==1){
                    grid[nx][ny]=0;
                    que.push({nx,ny});
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cout<<grid[i][j]<<" ";
                if(grid[i][j]==1)count++;
            }
            cout<<endl;
        }
        return count;
    }
};