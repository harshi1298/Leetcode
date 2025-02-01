class Solution {
    int row=0,col=0;
    int dfs(int x,int y,vector<vector<char>>&grid,vector<vector<bool>>&ans,int num){
        if(x<0 || y<0 || x>=row || y>=col || grid[x][y]=='0' || ans[x][y]==1)return 0;  
        ans[x][y]=1; 
        grid[x][y]=num;
        int k= 1+dfs(x-1,y,grid,ans,num)+dfs(x+1,y,grid,ans,num)+dfs(x,y-1,grid,ans,num)+dfs(x,y+1,grid,ans,num);
        return k;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
         row=grid.size();
         col=grid[0].size();
        vector<vector<bool>>ans(row,vector<bool>(col,0));
        unordered_map<int,int>mapp;
        int group_num=1;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1' && ans[i][j]==0){int k=dfs(i,j,grid,ans,group_num);mapp[group_num++]=k;}
            }
        }
        return mapp.size();
    }
};