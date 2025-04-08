class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = nums[i] -i;
        }
        unordered_map<int,int>mapp;
        long long ans=0;
        for(int i=0;i<n;i++){
           ans+=(i-mapp[arr[i]]);
           mapp[arr[i]]++;
        }
        return ans;
    }
};