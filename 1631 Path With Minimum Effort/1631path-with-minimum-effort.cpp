class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int row=h.size();
        int col=h[0].size();
        vector<vector<int>>ans(row,vector<int>(col,INT_MAX));
        queue<pair<int,int>>que;
        que.push({0,0});
        ans[0][0]=0;
        while(!que.empty()){
            int x=que.front().first;
            int y=que.front().second;
            que.pop();
            int indx[4]={0,0,1,-1};
            int indy[4]={1,-1,0,0};
            for(int i=0;i<4;i++){
                int nx=x+indx[i];
                int ny=y+indy[i];
                if(nx>=0 && ny>=0 && nx<row && ny<col){
                   if(ans[nx][ny]>max(ans[x][y],abs(h[nx][ny]-h[x][y]))){
                    ans[nx][ny]=max(ans[x][y],abs(h[nx][ny]-h[x][y]));
                    que.push({nx,ny});
                   }
                }
            }
        }
        return ans[row-1][col-1];
    }
};