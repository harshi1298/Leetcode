class Solution {
private:
    bool isvalid(int i){
        unordered_map<int,int>mapp;
        while(i>0){
           mapp[i%10]++;
           i/=10;
        }
        for(auto [ch,fr]: mapp){
            if(ch!=fr)return false;
        }
        return true;
    }
public:
    int nextBeautifulNumber(int n) {
        int maxi=1224444;
        for(int i=n+1;i<=1000000;i++){
            if(isvalid(i))return i;
        }
        return maxi;
    }
};