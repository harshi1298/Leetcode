class Solution {
public:
    bool winnerOfGame(string colors) {
        int count1=0;
        int count2=0;
        for(int i=0;i<colors.length();){
            int temp=0;
            while(i<colors.length() && colors[i]=='A'){
                temp++;
                i++;
            }
            if(temp/3>0){
                count1=count1+temp-2;
            }
            temp=0;
            while(i<colors.length() && colors[i]=='B'){
                temp++;
                i++;
            }
            if(temp/3>0){
                count2=count2+temp-2;
            }
        }
        return count1>count2;
    }
};