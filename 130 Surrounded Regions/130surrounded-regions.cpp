class Solution {
    int row, col;
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || y < 0 || x >= row || y >= col || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'S';
        dfs(board, x - 1, y);
        dfs(board, x + 1, y);
        dfs(board, x, y - 1);
        dfs(board, x, y + 1);
    }
public:
    void solve(vector<vector<char>>& board) {
        row = board.size();
        col = board[0].size();
        for (int i = 0; i < row; ++i) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][col - 1] == 'O') dfs(board, i, col - 1);
        }
        for (int j = 0; j < col; ++j) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[row - 1][j] == 'O') dfs(board, row - 1, j);
        }
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'S') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
