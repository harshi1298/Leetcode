class Solution {
private:
   int sum(int k){
    int s=0;
    while(k){
        s+=(k%10);
        k/=10;
    }
    return s;
   }
public:
    int getLucky(string s, int k) {
       vector<int>temp;
        for(int i=0;i<s.length();i++){
           temp.push_back(s[i]-'a'+1);
        }
        int s1=0;
        for(int i=0;i<temp.size();i++){s1+=sum(temp[i]);
        }
        k--;
        while(k){
           s1=sum(s1);
           k--;
        }
        return s1;
    }
};