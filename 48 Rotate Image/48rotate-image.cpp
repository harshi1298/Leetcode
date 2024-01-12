class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l=matrix.size();
        vector<vector<int>>ans(l,vector<int>(l));
        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                ans[i][j]=matrix[l-j-1][i];
            }
        }
     matrix=ans;   
    }
};