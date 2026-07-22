class Solution {
private:
    bool process(string &s,string &str){
        int n=s.length();
        int ones=0,addOnes=0;
        for(int i=0;i<n;i++){
            if(s[i]==str[i]) continue;
            else if(str[i]=='?'){
                if(s[i]=='1'){
                    addOnes++;
                }
                else if(ones){
                    ones--;
                    addOnes++;
                }
            }
            else if(s[i]=='0'){
                if(ones) ones--;
                else if(addOnes) addOnes--;
                else return false;
            }
            else {
                ones++;
            }
            // cout<<ones<<" "<<addOnes<<" "<<endl;
        }
        // cout<<endl;
        return ones==0;
    }
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        vector<bool> ans;
        for(auto &str:strs){
            ans.push_back(process(s,str));
        }
        return ans;
    }
};
