class Solution {
public:
    int lengthOfLastWord(string s) {
        int k=s.length()-1;
        int l=0;
        while(s[k]==' '){
          k--;
        }
         while(s[k]!=' '){
          l++;
         if(k==0)
          break;
          k--;
        }

        return l;
    }
};