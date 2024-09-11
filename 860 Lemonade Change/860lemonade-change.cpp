class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
       int size=bills.size();
       cout<<size<<endl;
       unordered_map<int,int>mapp;
       for(int i=0;i<size;i++){
        if(bills[i]==5){
            mapp[5]++;
        }
        else if(bills[i]==10){
            if(mapp[5]){
               mapp[5]--;
               mapp[10]++;
            }
            else return false;
        }
        else{
            if(mapp[5] && mapp[10]){
                mapp[5]--;
                mapp[10]--;
                mapp[20]++;
            }
            else if(mapp[5]>=3){
                mapp[5]=mapp[5]-3;
            }
            else return false;
        }
       } 
       return true;
    }
};