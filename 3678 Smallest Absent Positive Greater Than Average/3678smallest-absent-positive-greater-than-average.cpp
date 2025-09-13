#include <bits/stdc++.h>
using namespace std;
#define pr pair<int,int>
#define tp tuple<int,int,int>

class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int total=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        int avg=(total+n)/n;
        unordered_set<int>st;
        for(auto it : nums)st.insert(it);
        avg=avg<1?1:avg;
        for(int i=avg;i<=101;i++){
            if(st.find(i)==st.end())return i;
        }
        return 0;
    }
};