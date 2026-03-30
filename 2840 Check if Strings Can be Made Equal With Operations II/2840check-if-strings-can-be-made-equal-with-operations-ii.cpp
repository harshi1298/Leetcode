class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<char>s1e,s1o,s2e,s2o;
        int n=s1.length();
        for(int i=0;i<n;i++){
            if(i%2){
                s1o.push_back(s1[i]);
                s2o.push_back(s2[i]);
            }
            else{
                s1e.push_back(s1[i]);
                s2e.push_back(s2[i]);
               }
        }
        sort(s1o.begin(),s1o.end());
        sort(s1e.begin(),s1e.end());
        sort(s2o.begin(),s2o.end());
        sort(s2e.begin(),s2e.end());
        return (s1o==s2o) && (s1e==s2e);
    }
};