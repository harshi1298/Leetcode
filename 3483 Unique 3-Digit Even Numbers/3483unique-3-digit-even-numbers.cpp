class Solution {
private:
    unordered_set<int>st;
    void solve(vector<int>&digits,int num,vector<int>&vis){
        if(num>=100){
            if(num%2==0){
                st.insert(num);
            }
            return;
        }
        for(int i=0;i<digits.size();i++){
            if(!vis[i]){
                vis[i]=1;
                solve(digits,num*10+digits[i],vis);
                vis[i]=0;
            }
        }
    }
public:
    int totalNumbers(vector<int>& digits) {
        vector<int>vis(digits.size(),0);
       solve(digits,0,vis);
       return st.size();
    }
};