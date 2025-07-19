class Solution {
public:
    vector<string> removeSubfolders(vector<string>& f) {
        unordered_set<string>st;
        int n=f.size();
        sort(f.begin(),f.end(),[&](auto a,auto b){
            return a.length()<b.length();
        });
        for(int i=0;i<n;i++){
           string temp="";
           int k=0;
           while(k<f[i].length() && st.find(temp)==st.end()){
            temp+='/';
            k++;
            while(k<f[i].length() && f[i][k]!='/'){
            temp.push_back(f[i][k]);
            k++;
           }
        }
        if(k==f[i].length())st.insert(temp);
        }
        vector<string>ans(st.begin(),st.end());
        return ans;
    }
};