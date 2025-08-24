class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>&grid) {
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            int count=0;
            int l=col-1;
            for(int j=col-1;j>=0;j--){
                if(grid[i][j]=='*'){
                   for(int k=l;k>j;k--){
                    if(count>0){
                        grid[i][k]='#';
                        count--;
                    }
                    else grid[i][k]='.';
                   }
                    l=j-1;
                }
                else if(grid[i][j]=='#')count++;
            }
            if(count>0){
                for(int k=l;k>=0;k--){
                    if(count>0){
                        grid[i][k]='#';
                        count--;
                    }
                    else grid[i][k]='.';
                   }
            }
        }
        vector<vector<char>>ans(col,vector<char>(row));
          for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ans[j][row - 1 - i] = grid[i][j];
            }
          }
        return ans;
    }
};