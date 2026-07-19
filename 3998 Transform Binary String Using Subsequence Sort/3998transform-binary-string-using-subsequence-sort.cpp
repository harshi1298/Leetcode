class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n=s.length();
        vector<int>temp(n);
        temp[0]=s[0]=='0';
        for(int i=1;i<n;i++){
            temp[i]=temp[i-1]+(s[i]=='0');
        }
        vector<bool>ans;
        for(auto it : strs){
            bool t=1;
            int count1=0,count2=0;
           for(int i=0;i<n;i++){
              count1+=it[i]=='0';
              count2+=it[i]=='?';
              if(temp[i]>count1+count2){
                t=0;
                break;
              }
              else if(temp[i]>count1){
                count2-=(temp[i]-count1);
                count1=temp[i];
              }
           }
           if(count1>temp[n-1] || (n-count1-count2)>(n-temp[n-1]))t=0;
           ans.push_back(t);
        }
        return ans;
    }
};