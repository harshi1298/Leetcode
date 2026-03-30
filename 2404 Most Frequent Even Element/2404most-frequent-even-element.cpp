class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>mapp;
        int maxi=0;
        for(auto it : nums){
            if(it%2==0){mapp[it]++;
            maxi=max(maxi,mapp[it]);}
        }
        for(auto [key,val]: mapp){
            if(val==maxi)return key;
        }
    return -1;
    }
};