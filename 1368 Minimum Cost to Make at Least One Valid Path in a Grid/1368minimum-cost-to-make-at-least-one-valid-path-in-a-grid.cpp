class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>ans(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>>que;
        que.push({0,0});
        ans[0][0]=0;
        int indx[4]={1,-1,0,0};
        int indy[4]={0,0,1,-1};
        while(!que.empty()){
          int x=que.front().first;
          int y=que.front().second;
          que.pop();
          for(int i=0;i<4;i++){
            int nx=x+indx[i];
            int ny=y+indy[i];
            if(nx>=0 && ny>=0 && nx<m && ny<n){
                int temp;
                if(indx[i]==1 && indy[i]==0){
                   if(grid[x][y]==3){
                    temp=min(ans[nx][ny],ans[x][y]);
                   }
                   else{
                    temp=min(ans[nx][ny],ans[x][y]+1);
                   }
                }
                else if(indx[i]==-1 && indy[i]==0){
                     if(grid[x][y]==4){
                    temp=min(ans[nx][ny],ans[x][y]);
                   }
                   else{
                   temp=min(ans[nx][ny],ans[x][y]+1);
                   }
                }
                else if(indx[i]==0 && indy[i]==1){
                   if(grid[x][y]==1){
                    temp=min(ans[nx][ny],ans[x][y]);
                   }
                   else{
                    temp=min(ans[nx][ny],ans[x][y]+1);
                   }
                }
                else{
                    if(grid[x][y]==2){
                    temp=min(ans[nx][ny],ans[x][y]);
                   }
                   else{
                    temp=min(ans[nx][ny],ans[x][y]+1);
                   }
                }
                if(ans[nx][ny]>temp){
                   ans[nx][ny]=temp;
                   que.push({nx,ny});
                }
            }
          }
        }
        return ans[m-1][n-1];
    }
};