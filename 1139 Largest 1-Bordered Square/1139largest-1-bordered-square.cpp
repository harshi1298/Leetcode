class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        vector<vector<int>>temp=grid;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j])grid[i][j]+=grid[i][j-1];
            }
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(temp[i][j])temp[i][j]+=temp[i-1][j];
            }
        }
        int ans=0;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int l=min(grid[i][j],temp[i][j]);
                int x=i-l+1,y=j-l+1;
                 while (l > ans) {
                    int x = i - l + 1, y = j - l + 1;
                    if (x >= 0 && y >= 0 && temp[i][y] >= l && grid[x][j] >= l)
                        ans = l;
                    l--;
                }
            }
        }

        return ans*ans;
    }
};