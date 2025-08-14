class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        int n=num.length();
        for(int i=0;i<n-2;i++){
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                string temp=num.substr(i,3);
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};