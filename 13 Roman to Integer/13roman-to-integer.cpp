class Solution {
public:
    int value(char a){
        switch(a){
            case 'I':
               return 1;
            case 'V':
               return 5;
            case 'X':
               return 10;
            case 'L':
               return 50;
            case 'C':
               return 100;
            case 'D':
               return 500;
            default:
               return 1000;
               
        }
    }
    int romanToInt(string s) {
        int k=s.length();
        int l=0;
        for(int i=0;i<k;i++){
            if(i<k-1 && value(s[i])<value(s[i+1]))
               l=l-value(s[i]);
            else
               l=l+value(s[i]);
               cout<<l<<" ";
        }
      return l;
    }
};