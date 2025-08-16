class Solution {
private:
    vector<string>ans;
    vector<string> temp = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(int idx,string &str,string t){
        int n=str.length();
        if(idx>=n){
           ans.push_back(t);
           return ;
        }
        int l=str[idx]-'0'-2;
        for(int k=0;k<temp[l].length();k++){
            solve(idx+1,str,t+temp[l][k]);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)return ans;
        solve(0,digits,"");
        return ans;
    }
};