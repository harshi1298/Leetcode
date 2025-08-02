class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        int n = costs.size();
        int i = 0, j = n - 1;
        long long ans = 0;

        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        while (i <= j && pq1.size() < c) {
            pq1.push(costs[i++]);
        }
        while (j >= i && pq2.size() < c) {
            pq2.push(costs[j--]);
        }

        while (k--) {
            int val1 = pq1.empty() ? INT_MAX : pq1.top();
            int val2 = pq2.empty() ? INT_MAX : pq2.top();

            if (val1 <= val2) {
                ans += val1;
                pq1.pop();
                if (i <= j) pq1.push(costs[i++]);
            } else {
                ans += val2;
                pq2.pop();
                if (i <= j) pq2.push(costs[j--]);
            }
        }

        return ans;
    }
};
