class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int rmin=n,rmax=0,cmin=m,cmax=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    rmin=min(rmin,i);
                    rmax=max(rmax,i);
                    cmin=min(cmin,j);
                    cmax=max(cmax,j);
                }
            }
        }
        return (rmax-rmin+1)*(cmax-cmin+1);
    }
};