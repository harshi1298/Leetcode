class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int>mapp;
        for(int i=0;i<arr.size();i++){
            mapp[arr[i]]++;
        }
        int l=0;
        int m=1000;
        for(int i=1;i<=2*m;i++){
             if(mapp[i]==0) {
                l++;
                m++;
             }
             if(l==k)return i;
        }
        return -1;
    }
};