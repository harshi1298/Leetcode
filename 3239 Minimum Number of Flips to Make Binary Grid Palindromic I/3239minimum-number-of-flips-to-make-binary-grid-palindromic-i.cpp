class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int ansrow=0;
        int anscol=0;
        for(int i=0;i<row;i++){
            int j=0,k=col-1;
            while(j<k){
                if(grid[i][j]!=grid[i][k]){
                    ansrow++;}
                    j++;
                    k--;
 
            }
        }
             for(int i=0;i<col;i++){
            int j=0,k=row-1;
            while(j<k){
                 if(grid[j][i]!=grid[k][i]){
                     anscol++;
       }
                    j++;
                    k--;
            }
        }
        return min(ansrow,anscol);
    }
};