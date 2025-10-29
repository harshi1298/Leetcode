class Solution {
private:
    int leftBound(vector<int>& a, int val) {
        int l = 0, r = a.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (a[m] < val)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }

    int rightBound(vector<int>& a, int val) {
        int l = 0, r = a.size() - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (a[m] > val)
                r = m - 1;
            else
                l = m;
        }
        return l;
    }

    int maxFrequency1(vector<int>& a, int k, int op) {
        sort(a.begin(), a.end());
        int n = a.size(), ans = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
           freq[a[i]]++;
           ans=max(ans,freq[a[i]]);
        }
        for (auto i: a) {
            int l = leftBound(a,1ll*i-1ll* k);
            int r = rightBound(a,1ll*i+ 1ll*k);
            int cur = r - l + 1;
            if (freq.count(i))
                cur = min(cur, freq[i] + op);
            else
                cur = min(cur, op);
            ans = max(ans, cur);
        }
        return ans;
    }
public:
    int maxFrequency(vector<int>& nums, int k, int op) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),l=0;
        int ans=maxFrequency1(nums,k,op);
        for(int r=0;r<n;r++){
            while(1ll*nums[l]+1ll*2*k<1ll*nums[r]){
                l++;
            }
            int t=r-l+1;
            t=min(t,op);
            ans=max(ans,t);
        }
        return ans;
    }
};