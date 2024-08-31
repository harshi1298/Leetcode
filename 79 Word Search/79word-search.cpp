class Solution {
private:
   bool solve(vector<vector<char>>& board, string& word,int i,int j,int l,vector<vector<bool>>&m){
    if(l==word.length() || i<0 || j<0 || i>=board.size()|| j>=board[0].size()){
         if(l==word.length()) return true;
         else return false;
    }
    bool flag=false;
    m[i][j]=true;
    if( i<board.size()-1 &&!m[i+1][j] &&  !flag && word[l]==board[i+1][j])flag=solve(board,word,i+1,j,l+1,m);
    if(j<board[0].size()-1 &&!m[i][j+1] && !flag && word[l]==board[i][j+1])flag=solve(board,word,i,j+1,l+1,m);
    if(j>0 && !m[i][j-1] &&!flag && word[l]==board[i][j-1])flag=solve(board,word,i,j-1,l+1,m);
    if( i>0 &&!m[i-1][j] &&!flag && word[l]==board[i-1][j])flag=solve(board,word,i-1,j,l+1,m);
    m[i][j]=false;
    return flag;
   }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        vector<vector<bool>> m(row,vector<bool>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){
                    if(solve(board,word,i,j,1,m)){
                       return true;
                    }
                }
            }
        }
        return false;
    }
};