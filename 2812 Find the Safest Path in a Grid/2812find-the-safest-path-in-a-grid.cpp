#define pr pair<int,int>
#define tp tuple<int,int,int>
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>maxscore(n,vector<int>(n,INT_MAX));
        queue<pr>que;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){que.push(make_pair(i,j));
                maxscore[i][j]=0;}
            }
        }
        int indx[4]={1,-1,0,0};
        int indy[4]={0,0,-1,1};
        while(!que.empty()){
            auto [x,y]=que.front();
            que.pop();
            for(int i=0;i<4;i++){
                int nx=x+indx[i];
                int ny=y+indy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<n && maxscore[x][y]+1<maxscore[nx][ny]){
                    maxscore[nx][ny]=maxscore[x][y]+1;
                    que.push(make_pair(nx,ny));
                }
            }
        }
        priority_queue<tp>qu;
        int ans=-1;
        vector<vector<int>>vis(n,vector<int>(n,INT_MIN));
        qu.push(make_tuple(maxscore[0][0],0,0));
        while(!qu.empty()){
            auto [sc,x,y]=qu.top();
            qu.pop();
            if(sc<=vis[x][y])continue;
            vis[x][y]=sc;
            // cout<<x<<" "<<y<<" "<<sc<<endl;
            if(x==n-1 && y==n-1){
               return sc;
            }
            for(int i=0;i<4;i++){
                int nx=x+indx[i];
                int ny=y+indy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && vis[nx][ny] < min(sc, maxscore[nx][ny])){
                    int t=min(sc,maxscore[nx][ny]);
                    qu.push(make_tuple(t,nx,ny));
                }
            }
        }
        return ans;
    }
};