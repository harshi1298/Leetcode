class Solution {
private:
    int ans=INT_MAX;
    pair<int, int> find(int cell, int n) {
        int row = n - 1 - (cell - 1) / n;
        int col = (cell - 1) % n;
        if ((n - row) % 2 == 0) col = n - 1 - col;
        return {row, col};
    }

    void solve(vector<vector<int>>&board,int cell,int temp,int n,vector<int>&vis){
        if (cell > n * n || vis[cell] <= temp) return;
        if(cell==n*n){
            ans=min(ans,temp);
        }
        vis[cell]=temp;
        for(int k=1;k<=6;k++){
            int next=cell+k;
            if(next>n*n)return;
            auto [row,col]=find(next,n);
            if(board[row][col]!=-1)next=board[row][col];
            solve(board,next,temp+1,n,vis);
        }
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int>vis(n*n+1,INT_MAX);
        solve(board,1,0,n,vis);
        return ans==INT_MAX?-1:ans;
    }
};