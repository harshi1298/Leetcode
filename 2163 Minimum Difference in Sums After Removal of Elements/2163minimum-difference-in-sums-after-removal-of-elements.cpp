
class Solution
{
public:
    long long minimumDifference(vector<int> &nums)
    {
        int n = nums.size(), k = n / 3;
        priority_queue<int, vector<int>, greater<int>> minheap;
        priority_queue<int> maxheap;

        vector<long long> minsum(n, 1e12);
        vector<long long> maxsum(n, -1e12);

        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (maxheap.size() < k)
            {
                sum += nums[i];
                maxheap.push(nums[i]);
            }
            else
            {
                sum += nums[i];
                maxheap.push(nums[i]);
                sum -= maxheap.top();
                maxheap.pop();
               
            }
            if(maxheap.size()==k) minsum[i] = sum;
        }

        sum = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (minheap.size() < k)
            {
                sum += nums[i];
                minheap.push(nums[i]);
            }
            else
            {
                sum += nums[i];
                minheap.push(nums[i]);
                sum -= minheap.top();
                minheap.pop();
            }
            if(minheap.size()==k)maxsum[i] = sum;
        }

        long long ans = 1e12;
        for (int i = 0; i < n - 1; i++)
        {
            if (minsum[i] < 1e12 && maxsum[i + 1] > -1e12)
            {
                ans = min(ans, minsum[i] - maxsum[i + 1]);
            }
        }

        return ans;
    }
};
