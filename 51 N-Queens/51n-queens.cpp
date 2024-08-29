class Solution {
private:
    bool ispossible(int row,int col,vector<string> ans1,int n){
        int r=row,c=col;
        while(r>=0 && c>=0){
            if(ans1[r][c]=='Q')
              return false;
            r--;
            c--;
        }
        r=row,c=col;
        while(r<n && c>=0){
            if(ans1[r][c]=='Q')
              return false;
            r++;
            c--;
        }
        r=row,c=col;
        while(c>=0){
             if(ans1[r][c]=='Q')
              return false;
            c--;
        }
        return true;
    }
    void solve(int n,vector<string> ans1,vector<vector<string>> &ans,int ind){
       if(ind==n){
        ans.push_back(ans1);
        return;
       }
       for(int i=0;i<n;i++){
          if(ispossible(i,ind,ans1,n)){
            ans1[i][ind]='Q';
            solve(n,ans1,ans,ind+1);
            ans1[i][ind]='.';
          }
       }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s(n,'.');
        vector<string>ans1(n,s);
        solve(n,ans1,ans,0);
        return ans;
    }
};