class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp1(n,vector<int>(m,0));
        vector<vector<int>>dp2(n,vector<int>(m,0));
        vector<int>above(n),below(n);
        vector<int>left(m),right(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    if(i==0 || j==0)dp1[i][j]=1;
                    else dp1[i][j]=min({dp1[i-1][j],dp1[i][j-1],dp1[i-1][j-1]})+1;
                }
                if(i==0)above[i]=max(above[i],dp1[i][j]);
                else  above[i]=max({above[i-1],above[i],dp1[i][j]});
                if(j==0)left[j]=max(left[j],dp1[i][j]);
                else  left[j]=max({left[j-1],left[j],dp1[i][j]});
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(mat[i][j]){
                    if(i==n-1 || j==m-1)dp2[i][j]=1;
                    else dp2[i][j]=min({dp2[i+1][j],dp2[i][j+1],dp2[i+1][j+1]})+1;
                }
                if(i==n-1)below[i]=max(below[i],dp2[i][j]);
                else  below[i]=max({below[i+1],below[i],dp2[i][j]});
                if(j==m-1)right[j]=max(right[j],dp2[i][j]);
                else  right[j]=max({right[j+1],right[j],dp2[i][j]});
            }
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
           ans=max(ans,min(above[i],below[i+1]));
        }
        for(int j=0;j<m-1;j++){
           ans=max(ans,min(left[j],right[j+1]));
        }
        return ans*ans;
    }
};