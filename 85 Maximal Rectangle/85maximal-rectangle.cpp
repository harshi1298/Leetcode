class Solution {
private:
    int solve(vector<int>&h){
        int n=h.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int mini=h[i];
            for(int j=i;j<n;j++){
              mini=min(mini,h[j]);
              ans=max(ans,mini*(j-i+1));
            }
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int>h(m);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    h[j]=0;
                }
                else h[j]++;
            }
            ans=max(ans,solve(h));
        }
        return ans;
    }
};