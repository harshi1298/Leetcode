class Solution {
private:
    set<pair<int,int>> st;//start, size
    bool solve(int idx,string &s,set<string>&mapp){
        if(idx>=s.length()){
            return true;
        }
        for(int i=idx+1;i<=s.length();i++){
            if(st.find({idx,i-idx})!=st.end()){
                continue;
            }
            string temp=s.substr(idx,i-idx);
            if( mapp.find(temp)!=mapp.end()){
                if(solve(i,s,mapp))return true;
                else st.insert({idx,i-idx});
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& w) {
        set<string >mapp;
        for(int i=0;i<w.size();i++){
            mapp.insert(w[i]);
        }
        return solve(0,s,mapp);
    
    }
};