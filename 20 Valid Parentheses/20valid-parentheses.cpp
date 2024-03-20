class Solution {
public:
    int check(char a, char b){
        if(a=='('&&b==')')
          return 1;
        else if(a=='{'&&b=='}')
          return 1;
        else if(a=='['&&b==']')
          return 1;
        else return 0;
    }
    bool isValid(string s) {
      int k=s.length();
      char arr[k];
      int top=-1,i=0;
      while(i<k){
        if(top==-1){
            top++;
            arr[top]=s[i];
            i++;
            continue;
        }
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
        top++;
        arr[top]=s[i];}
        else{
        int k=check(arr[top],s[i]);
        if(k)
         top--;
        else
          return false;
         } 
         i++;      
      } 
      if(top==-1)
        return true;
    return false;                                                                                                                                                                                                                                                                                                                                             
    }
};