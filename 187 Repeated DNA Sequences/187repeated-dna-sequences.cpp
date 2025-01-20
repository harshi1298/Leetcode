class Solution {
    private:
    int val(char &a){
        switch(a){
            case 'A': return 1;
            case 'C': return 2;
            case 'G': return 3;
            default: return 4;
        }
    }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<10){
            return {};
        }
        vector<string> ans;
        map<long long,string> mapp;
        int i=0;
        long long sum=0;
        long long MOD=1e10;
        for(;i<9;i++){
            int v=val(s[i]);
            sum+=v;
            sum*=10;
        }
        for(;i<s.length();i++){
            sum%=MOD;
            sum+=val(s[i]);
            if(mapp.find(sum)!=mapp.end()){
                if(mapp[sum]!="#") {
                    ans.push_back(mapp[sum]);
                    mapp[sum]="#";
                }
            }
            else{
                mapp[sum]=s.substr(i-9,10);
            }
            sum*=10;
        }
        return ans;
    }
};