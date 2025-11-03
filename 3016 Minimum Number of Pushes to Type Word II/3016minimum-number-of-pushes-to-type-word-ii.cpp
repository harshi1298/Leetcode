class Solution {
public:
    int minimumPushes(string word) {
        vector<int>arr(26,0);
        for(auto it : word)arr[it-'a']++;
        sort(arr.rbegin(),arr.rend());
        int ans=0;
        for(int i=0;i<24;i++){
           ans+=(arr[i]*(i/8+1));
        }
        ans+=arr[24]*4;
        ans+=arr[25]*4;
        return ans;
    }
};