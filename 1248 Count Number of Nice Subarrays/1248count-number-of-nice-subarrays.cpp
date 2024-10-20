class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
    
    int atMostK(vector<int>& nums, int k) {
        int count = 0, left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] % 2 != 0) k--;
            while (k < 0) {
                if (nums[left] % 2 != 0) k++;
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
};

