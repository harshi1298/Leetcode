class Solution {
public:
    int maxFreqSum(string s) {
       int l=s.length();
        unordered_map<char,int>mapp;
        for(int i=0;i<l;i++){
            mapp[s[i]]++;
        }
        int t1=0,t2=0;
        for(auto it :mapp){
            if(it.first=='a' ||it.first=='e' || it.first=='i' || it.first=='o' ||it.first=='u'){
                t1=max(t1,it.second);
            }
            else t2=max(t2,it.second);
        }
        return t1+t2;
    }
};