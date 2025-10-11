class Solution {
public:
    bool scoreBalance(string s) {
        int total=0;
        for(auto it : s){
            total+=(it-'a'+1);
        }
        if(total%2)return false;
        int count=0;
        for(int i=0;i<s.length();i++){
            count+=s[i]-'a'+1;
            if(total==count*2)return true;
        }
        return false;
    }
};