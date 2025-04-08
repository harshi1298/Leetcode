class Solution {
private:
    int modulo=1e9+7;
    int reverse(int n) {
        int reversed_number = 0;
        while (n != 0) {
            int remainder = n % 10;
            reversed_number = reversed_number * 10 + remainder;
            n /= 10;
        }
        return reversed_number;
    }

public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = nums[i] -reverse(nums[i]);
        }
        unordered_map<int,int>mapp;
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=mapp[arr[i]];
            mapp[arr[i]]++;
            ans=ans%modulo;
        }
        return ans;
    }
};