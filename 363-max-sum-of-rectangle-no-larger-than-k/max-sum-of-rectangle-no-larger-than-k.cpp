class Solution {
private:
int solve(vector<int>& arr, int k) {
   set<int>st;
   int sum=0;
   int ans=INT_MIN;
   st.insert(0);
   for(int i=0;i<arr.size();i++){
      sum+=arr[i];
      auto it =st.lower_bound(sum-k);
      if(it!=st.end())ans=max(ans,sum-*it);
      st.insert(sum);
   }
   return ans;
}

public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ans=INT_MIN;
        int row=matrix.size(),col=matrix[0].size();
        for(int i=0;i<row;i++){
            vector<int>pre(col,0);
            for(int j=i;j<row;j++){
               for(int k=0;k<col;k++){
                  pre[k]+=matrix[j][k];
               }
            ans=max(ans,solve(pre,k));
            }
        }
        return ans;
    }
};