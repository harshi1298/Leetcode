class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long>avail(n);
        vector<long long>count(n);
        sort(meetings.begin(),meetings.end());
        for(auto &m : meetings){
            long long st=m[0],end=m[1];
            long long availtime=LLONG_MAX;
            long long availroom=-1;
            bool flag=1;
            for(long long i=0;i<n;i++){
                if(avail[i]<=st){
                    count[i]++;
                    avail[i]=end;
                    flag=0;
                    break;
                }
                if(avail[i]>st && avail[i]<availtime){
                    availtime=avail[i];
                    availroom=i;
                }
            }
            if(flag){
                avail[availroom]+=(end-st);
                count[availroom]++;
            }
        }
        long long maxi=*max_element(count.begin(),count.end());
        for(int i=0;i<n;i++){
            if(count[i]==maxi)return i;
        }
        return 0;
    }
};