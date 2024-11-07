class Solution {
private:
   int count(int a){
    int count1=0;
    while(a){
        if(a&1)count1++;
        a=a>>1;
    }
    return count1;
   }
public:
    vector<int> sortByBits(vector<int>& arr) {
       sort(arr.begin(),arr.end(),[&](auto a,auto b){
        int k=count(a);
        int l=count(b);
        if(k==l)return a<b;
        else return k<l;
       }) ;
       return arr;
    }
};