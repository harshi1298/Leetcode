class Solution {
private:
    bool ispossible(vector<vector<char>>& board,int row,int col,vector<unordered_map<int,bool>>mapp){
        int box=(row/3)*3+col/3;
        if(mapp[box].find(board[row][col])!=mapp[box].end() && mapp[box][board[row][col]])return false;
        for(int i=row-1;i>=0;i--){
            if(board[i][col]==board[row][col])return false;
        }
        for(int i=col-1;i>=0;i--){
            if(board[row][i]==board[row][col])return false;
        }
        for(int i=row+1;i<board.size();i++){
            if(board[i][col]==board[row][col])return false;
        }
        for(int i=col+1;i<board.size();i++){
            if(board[row][i]==board[row][col])return false;
        }
      return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int,bool>>mapp(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                   if(!ispossible(board,i,j,mapp))return false;
                   else {
                     int box=(i/3)*3+j/3;
                     mapp[box][board[i][j]]=true;
                   }
                }
            }
        }
        return true;
    }
};