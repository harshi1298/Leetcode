class Solution {
public:
    bool isBalanced(string num) {
        int count1=0;
        int count2=0;
        for(int i=0;i<num.length();i++){
            if(i%2){
                count1=(int)(num[i]-'0')+count1;
            }
            else count2=(int)(num[i]-'0')+count2;
        }
        return count1==count2;
    }
};