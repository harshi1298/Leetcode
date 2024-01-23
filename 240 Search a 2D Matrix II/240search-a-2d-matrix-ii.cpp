class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = n-1;

        while(start < m && end >= 0){
            if(matrix[start][end] == target){
                return true;
            }

            if(target > matrix[start][end]){
                start++;
            }
            else{
                end--;
            }
        }

        return false;
    }
};