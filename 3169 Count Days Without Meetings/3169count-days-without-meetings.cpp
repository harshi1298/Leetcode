class Solution {
public:
    int countDays(int days, vector<vector<int>>& meet) {
        sort(meet.begin(),meet.end(),[&](auto a,auto b){
            return a[0]<b[0];
        });
        int ans=meet[0][0]-1;
        int last=meet[0][1];
        for(int i=1;i<meet.size();i++){
            last=max(last,meet[i-1][1]);
            if(last<meet[i][0]){
                ans+=(meet[i][0]-last-1);
            }
        }
      last = max(last, (meet[meet.size() - 1][1]));
        ans+=(days-last);
        return ans;
    }
};