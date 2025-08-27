class Solution {
private:
    vector<vector<vector<vector<int>>>>dp;
    int indx[4]={1,1,-1,-1};
    int indy[4]={-1,1,1,-1};
    int solve(vector<vector<int>>& grid,int x,int y,int turn,int d,int t){
        int n=grid.size(),m=grid[0].size();
        if (dp[x][y][d][turn] != -1) return dp[x][y][d][turn];
        int nx=x+indx[d];
        int ny=y+indy[d];
        if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny]!=t)return 0;
        int temp=solve(grid,nx,ny,turn,d,2-t);
        if(!turn){
            temp=max(temp,solve(grid,nx,ny,(!turn),(d+3)%4,2-t));
        }
        return dp[x][y][d][turn]=temp+1;
    }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        dp.assign(n, vector<vector<vector<int>>>(m, vector<vector<int>>(4, vector<int>(2, -1))));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        ans=max(ans,solve(grid,i,j,0,k,2)+1);
                    }
                }
            }
        }
        return ans;
    }
};