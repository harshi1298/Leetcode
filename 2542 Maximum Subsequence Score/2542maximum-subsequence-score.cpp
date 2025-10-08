class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairs;
        for (int i = 0; i < n; ++i) {
            pairs.push_back({nums2[i], nums1[i]});
        }
        sort(pairs.rbegin(), pairs.rend());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0, result = 0;
        for (int i = 0; i < n; ++i) {
            int currNum1 = pairs[i].second;
            int currNum2 = pairs[i].first;
            minHeap.push(currNum1);
            sum += currNum1;
            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == k) {
                result = max(result, sum * (long long)currNum2);
            }
        }

        return result;
    }
};
