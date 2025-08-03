class Solution {
public:
    string removeDigit(string number, char digit) {
        string ans="";
        int n=number.size();
        for(int i=0;i<n;i++){
            if(number[i]==digit){
                string temp=number.substr(0,i);
                temp+=number.substr(i+1);
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};