class Solution {
public:
    bool isValid(string word) {
        if(word.length()<3)return false;
        bool t=false,t2=false;
        for(auto c: word){
            if(isalpha(c)){
                c=tolower(c);
                if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                    t=true;
                }
                else t2=true;
            }
            else if(!isdigit(c))return false;
        }
        return t && t2;
    }
};