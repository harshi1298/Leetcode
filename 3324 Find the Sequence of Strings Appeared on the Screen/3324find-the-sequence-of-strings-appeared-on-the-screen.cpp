class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string>ans;
        for(int i=0;i<target.length();i++){
          string tmp=target.substr(0,i);
          for(int j=0;j<=target[i]-'a';j++){
             ans.push_back(tmp+(char)('a'+j));
          }
        }
        return ans;
    }
};