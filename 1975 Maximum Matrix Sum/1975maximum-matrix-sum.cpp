class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        long long ans=0;
        int count=0,mini=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]<=0){
                    matrix[i][j]*=-1;
                    count++;
                }
                mini=min(matrix[i][j],mini);
                ans+=1ll*matrix[i][j];
            }
        }
        if(count%2)ans+=1ll*mini*-2;
        return ans;
    }
};