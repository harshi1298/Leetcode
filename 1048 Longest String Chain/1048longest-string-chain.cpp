class Solution {
private:
   bool check(string a, string b) {
      if(a.length()>b.length()){
        return check(b,a);
      }
      if(a.length()+1!=b.length()){
        return false;
      }
    //   cout<<a<<" "<<b<<endl;
      int j=0,i=0;
      bool flag=0;
       while(i<a.length()){
            if(a[i]==b[j]){
                j++;
                i++;
            }
            else if(!flag){
                flag=1;
                j++;
            }
            else{
                return false;
            }
            // cout<<a[i]<<" "<<b[j]<<" "<<flag<<endl;
       }
    //   cout<<a<<" "<<b<<endl;
       return true;
   }

   int solve(vector<string>& words, int i, int j, vector<vector<int>>& dp) {
      if(j >= words.size()) return 0;
      if(dp[i][j] != -1) return dp[i][j];
      if(check(words[i], words[j])) {
         return dp[i][j] = max(1 + solve(words, j, j + 1, dp), solve(words, i, j + 1, dp));
      }
      return dp[i][j] = max(solve(words, j, j + 1, dp), solve(words, i, j + 1, dp));
   }

public:
   int longestStrChain(vector<string>& words) {
      sort(words.begin(), words.end(), [&](auto a, auto b) {
         return a.length() < b.length();
      });
      int n=words.size();
    //   vector<vector<int>> dp(words.size(), vector<int>(words.size(), -1));
    //   return solve(words, 0, 0, dp) + 1;
    vector<int>dp(n,1);
    int ans=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
          if(check(words[j],words[i])){
            dp[i]=max(dp[i],dp[j]+1);
            ans=max(ans,dp[i]);
            // cout<<words[i]<<" "<<words[j]<<" "<<ans<<endl;
          }
        }
    }
    return ans;
   } 
};
