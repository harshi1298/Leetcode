class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        stringstream ss(s);
        string word, ans = "";
        while(ss>>word){
          reverse(word.begin(),word.end());
          ans=ans+word;
          ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};