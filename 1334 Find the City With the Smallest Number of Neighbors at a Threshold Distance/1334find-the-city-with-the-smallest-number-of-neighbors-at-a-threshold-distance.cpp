class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>>matrix(n,vector<int>(n,1e8));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)matrix[i][j]=0;
            }
        }
        for(auto e :edges){
            matrix[e[0]][e[1]]=e[2];
            matrix[e[1]][e[0]]=e[2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        int mini=INT_MAX,ans;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j&& matrix[i][j]<=d){
                   count++;
                }
            }
            if(mini>=count){
                mini=count;
                ans=i;
            }

        }
        return ans;
    }
};