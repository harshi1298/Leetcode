class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans(m,string(n,'#'));
        ans[0]=string(n,'.');
        for(auto &it : ans){
            it[n-1]='.';
        }
        return ans;
    }
};