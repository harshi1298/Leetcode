class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector <int> ans;
        int row= matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<row;i++){
            int high=0;
            int highnum=matrix[i][0];
            for(int j=0;j<col;j++){
                 if(highnum>matrix[i][j]){
                    highnum=matrix[i][j];
                    high=j;
                 }
            }
            int flag=1;
            for(int k=0;k<row;k++){
                if(matrix[k][high]>highnum) flag=0;
            }
            if(flag) ans.push_back(highnum);
        }
        return ans;
    }
};