class Solution {
private:
    bool isvalid(string &s ,int j){
        if(s[j]<='z' and s[j]>='a')return true;
        if(s[j]=='-'){
            if(j>0 && s[j-1]<='z' && s[j-1]>='a' && j<s.length()-1 && s[j+1]>='a' && s[j+1]<='z')return true;
        }
        return false;
    }
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s="";
        for(auto it : chunks)s+=it;
        string word;
        unordered_map<string,int>mapp;
        int i=0;
        while(i<s.length()){
            if (!isvalid(s,i)) {
                i++;
                continue;
            }
            int j=i;
            while(j<s.length() && isvalid(s,j))j++;
            string k=s.substr(i,j-i);
            mapp[k]++;
            i=j;
        }
        vector<int>ans;
        for(auto it : queries)ans.push_back(mapp[it]);
        return ans;
    }
};