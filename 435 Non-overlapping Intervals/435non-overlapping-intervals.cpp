class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](auto a,auto b){
            return a[1]<b[1];
        });
        int ans=0;
        int end=intervals[0][1];
       for(int i=0;i<intervals.size()-1;i++){
        if(end<=intervals[i+1][0]){
            end=intervals[i+1][1];
        }
        else{
            ans++;
        }
       }
       return ans;
    }
};