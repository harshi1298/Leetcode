class Solution {
private:
    vector<string>ans;
    void solve(int &n,string &s,int i){
        if(i>=n){
          ans.push_back(s);
          return ;
        }
        if(s.empty()|| s.back()=='1'){
            s.push_back('0');
            solve(n,s,i+1);
            s.pop_back();
            s.push_back('1');
            solve(n,s,i+1);
            s.pop_back();
        }
        else if(s.back()=='0'){
            s.push_back('1');
            solve(n,s,i+1);
            s.pop_back();
        }
    }
public:
    vector<string> validStrings(int n) {
        string s="";
        solve(n,s,0);
        return ans;
    }
};