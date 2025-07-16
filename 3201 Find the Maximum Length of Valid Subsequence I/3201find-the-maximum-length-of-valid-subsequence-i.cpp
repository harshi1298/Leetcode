class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int even_c = 0, odd_c = 0, odd_even_c = 0, even_odd_c = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0)
                even_c++;
            else
                odd_c++;
        }
        int t = 1;
        for (int i = 0; i < n; i++) {
            if (t && nums[i] % 2 != 0) {
                odd_even_c++;
                t = 0;
            }
            else if (!t && nums[i] % 2 == 0) { 
                odd_even_c++;
                t = 1;
            }
        }
        t = 0;
        for (int i = 0; i < n; i++) {
            if (!t && nums[i] % 2 == 0) { 
                even_odd_c++;
                t = 1;
            }
            else if (t && nums[i] % 2 != 0) { 
                even_odd_c++;
                t = 0;
            }
        }

        return max({even_c, odd_c, odd_even_c, even_odd_c});
    }
};
