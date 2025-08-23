class Solution {
    vector<string>ans;
    void solve(string &s,int idx,vector<string> temp){
        int n=s.length();
        if(temp.size()==4){
            if(idx!=n)return;
            string k="";
            for(auto it : temp){
                if(it.length()>1 && it[0]=='0')return ;
                k+=it;
                k.push_back('.');
            }
            k.pop_back();
            ans.push_back(k);
            return ;
        }
        if(idx>=n)return ;
        string t="";
        for(int i=idx,k=0;i<n && k<3;i++,k++){
             t.push_back(s[i]);
             if(stoi(t)<=255){
                temp.push_back(t);
                solve(s,i+1,temp);
                temp.pop_back();
             }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        solve(s,0,{});
        return ans;
    }
};