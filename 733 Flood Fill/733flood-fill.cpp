class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row=image.size();
        int col=image[0].size();
        queue<pair<int,pair<int,int>>>que;
        que.push({image[sr][sc],{sr,sc}});
        image[sr][sc]=color;
        vector<vector<int>>vis(row,vector<int>(col,0));
        while(!que.empty()){
            auto k=que.front();
            que.pop();
            int x=k.second.first;
            int y=k.second.second;
            int z=k.first;
            int indx[4]={-1,1,0,0};
            int indy[4]={0,0,-1,1};
            for(int i=0;i<4;i++){
                int nx=x+indx[i];
                int ny=y+indy[i];
                if(nx>=0 && ny>=0 && nx<row && ny<col && !vis[nx][ny] &&image[nx][ny]==z){
                    vis[nx][ny]=1;
                    image[nx][ny]=color;
                    que.push({z,{nx,ny}});
                }
            }
        }
        return image;
    }
};