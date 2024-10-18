class Solution {
public:
    bool checkValidString(string s) {
       int count1=0;
       int count2=0;
       for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            count1++;
            }
        if(s[i]==')'){
            if(count1>0)count1--;
            else if(count2>0)count2--;
            else return 0;
        }
        if(s[i]=='*')count2++;
       }
       int k=count1<=count2; 
        count1=0;
         count2=0;
       for(int i=s.length()-1;i>=0;i--){
        if(s[i]==')'){
            count1++;
            }
        if(s[i]=='('){
            if(count1>0)count1--;
            else if(count2>0)count2--;
            else return 0;
        }
        if(s[i]=='*')count2++;
       } 
       return k && count1<=count2;
       return false; 
    }
};