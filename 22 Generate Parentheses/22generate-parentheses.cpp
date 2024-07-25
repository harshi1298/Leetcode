class Solution {
private:
 void solve(vector<string> &ans,string str,int n,int open,int close){
        if(open==n && open == close){
             ans.push_back(str);
            return;
        }
        if(n>open){
            solve(ans,str+'(',n,open+1,close);
        }
        if(close<open){
            solve(ans,str+')',n,open,close+1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string output;
        vector<string> ans;
        solve(ans,output,n,0,0);
        return ans;
    }
};