class Solution {
public:
    string largestPalindromic(string num) {
        int n=num.length()-1;
        unordered_map<int,int>mapp;
        for(auto it : num){
            mapp[it-'0']++;
        }
        char mid='-';
        string ans="";
        for(int i=9;i>=0;i--){
            if(mapp[i]%2 && mid=='-'){
                mid=i+'0';
            }
            string temp(mapp[i]/2,i+'0');
            ans+=temp;
        }
        string temp=ans;
        reverse(temp.begin(),temp.end());
        if(mid!='-')ans.push_back(mid);
        ans=ans+temp;
        int j=ans.length()-1,i=0;
        while(i<ans.length() && ans[i]=='0'){
            i++;
        }
        while(j>=0 && ans[j]=='0')j--;
        int l=j-i+1;
        if(l<0)return "0";
        return ans.substr(i,l);
    }
};