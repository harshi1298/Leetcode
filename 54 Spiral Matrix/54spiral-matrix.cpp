class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int sr=0,sc=0,er=matrix.size()-1,ec=matrix[0].size()-1;
        int total=(er+1)*(ec+1),count=0;
        while(count<total){
            for(int i=sc;i<=ec&& count<total;i++){
                ans.push_back(matrix[sr][i]);
                count++;
            }
            sr++;
            for(int i=sr;i<=er&& count<total;i++){
                ans.push_back(matrix[i][ec]);
                count++;
            }
            ec--;
            for(int i=ec;i>=sc && count<total;i--){
                ans.push_back(matrix[er][i]);
                count++;
            }
            er--;
            for(int i=er; i>=sr&& count<total;i--){
                ans.push_back(matrix[i][sc]);
                count++;
            }
            sc++;
        }
        return ans;
    }
};