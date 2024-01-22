class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=s.size()-1;
        int i=0;
        while(i<=l){
            char temp=s[i];
            s[i]=s[l];
            s[l--]=temp;
            i++;
        }
    }
};