class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
     vector<pair<int,int>>zero;
     for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==0){
                zero.push_back({i,j});
            }
        }
     }  
     for(int i=0;i<zero.size();i++){
        for(int j=0;j<matrix[0].size();j++)matrix[zero[i].first][j]=0;
        for(int j=0;j<matrix.size();j++)matrix[j][zero[i].second]=0;
     } 
    }
};