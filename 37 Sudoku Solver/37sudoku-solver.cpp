class Solution {
private:
    bool isPossible(int i, int col, vector<vector<char>>& board, vector<unordered_map<int, bool>>& m, int fill) {
        char fillChar = char(fill + '0');
        int boxIndex = (i / 3) * 3 + (col / 3);
        if (m[boxIndex].find(fill) != m[boxIndex].end() && m[boxIndex][fill]) {
            return false;
        }
        for (int j = 0; j < 9; ++j) {
            if (board[j][col] == fillChar) {
                return false;
            }
        }
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == fillChar) {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<unordered_map<int, bool>>& m, vector<vector<char>>& board, int row, int col) {
        if (col == 9) {
            col = 0;
            row++;
            if (row == 9) {
                return true;
            }
        }
        if (board[row][col] != '.') {
            return solve(m, board, row, col + 1);
        }
        for (int fill = 1; fill <= 9; ++fill) {
            if (isPossible(row, col, board, m, fill)) {
                board[row][col] = char(fill + '0');
                int boxIndex = (row / 3) * 3 + (col / 3);
                m[boxIndex][fill] = true;

                if (solve(m, board, row, col + 1)) {
                    return true;
                }
                board[row][col] = '.';
                m[boxIndex][fill] = false;
            }
        }

        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int, bool>> m(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int fill = board[i][j] - '0';
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    m[boxIndex][fill] = true;
                }
            }
        }
        solve(m, board, 0, 0);
    }
};


// private:
//    bool ispossible(int i,int col,vector<vector<char>>& board,vector<unordered_map<int,bool>>m,int fill){
//         int r=i,c=col;
//         int k=i/3+(col/3)*3+1;
//         if(m[k][fill]==true)return false;
//         for(int j=i;j<9;j++){
//             if(board[j][col]==char(fill+'0'))return false;
//         }
//         r=i,c=col;
//         for(int j=col;j<9;j++){
//             if(board[j][col]==char(fill+'0'))return false;
//         }
//         return true;
//    }
//    void solve( vector<unordered_map<int,bool>>m,vector<vector<char>>& board,int row,int col,int fill){
//     if(col==9)return;
//     for(int i=row;i<9;i++){
//         if(board[i][col]=='.'){
//           if(ispossible(i,col,board,m,fill)){
//              board[i][col]=char(fill+'0');
//              solve(m,board,i+1,col,fill+1);
//              board[i][col]='.';
//           }
//           else{
//             fill++;
//           }
//         }
//         else{
//             int k=i/3+(col/3)*3+1;
//             int l=board[i][col]-'0';
//             m[k][l]=true;
//         }
//     }
//     solve(m,board,0,col+1,0);
//    }
// public:
//     void solveSudoku(vector<vector<char>>& board) {
//         unordered_map<int,bool>s;
//         for(int i=1;i<=9;i++){
//             s[i]=0;
//         }
//         vector<unordered_map<int,bool>>m(9,s);
//         solve(m,board,0,0,1);
//     }
// };