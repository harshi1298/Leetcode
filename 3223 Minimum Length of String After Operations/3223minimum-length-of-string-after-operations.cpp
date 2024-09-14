class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mapp;
        for(int i=0;i<s.length();i++){
            mapp[s[i]]++;
        }
        int k=s.length();
        for(auto i: mapp){
            if(i.second>2){
                int temp=((i.second-1)/2)*2;
                k=k-temp;
            }
        }
        return k;
    }
};