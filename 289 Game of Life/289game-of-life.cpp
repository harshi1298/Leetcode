class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
        int idx[8]={0,0,1,1,1,-1,-1,-1};
        int idy[8]={-1,1,0,1,-1,0,1,-1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count=0;
                for(int k=0;k<8;k++){
                  int x=i+idx[k],y=idy[k]+j;
                  if(x>=0 && y>=0 && x<m && y<n && (board[x][y]==1|| board[x][y]==3)){
                    count++;
                  }
                }
                if((count<2 || count>3) && board[i][j]==1)board[i][j]=3;
                if(count==3 && board[i][j]==0){
                   board[i][j]=2;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==3)board[i][j]=0;
                if(board[i][j]==2)board[i][j]=1;
            }
        }
    }
};