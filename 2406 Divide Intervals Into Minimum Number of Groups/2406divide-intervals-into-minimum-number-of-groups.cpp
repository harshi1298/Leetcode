class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](auto a,auto b){
            return a[1]>b[1];
        });
        multiset<int>st;
        st.insert(intervals[0][0]);
        for(int i=1;i<intervals.size();i++){
           auto it=st.upper_bound(intervals[i][1]);
           if(it==st.end())st.insert(intervals[i][0]);
           else{
            st.erase(it);
            st.insert(intervals[i][0]);
           }
        }
        return st.size();
    }
};