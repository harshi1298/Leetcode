class Solution {
private:
    bool isvalid(int a, int b) {
        int count1 = 0, count2 = 0;
        while (a || b) {
            if (a & 1)
                count1++;
            if (b & 1)
                count2++;
            a = a >> 1;
            b = b >> 1;
        }
        return count1 == count2;
    }

public:
    bool canSortArray(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            bool flag = false;
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1] && isvalid(arr[j], arr[j + 1])) {
                    swap(arr[j], arr[j + 1]);
                    flag = true;
                }
            }
            if (!flag)
                break;
        }
        int i = 0;
        while (i < n - 1 && arr[i] <= arr[i + 1])
            i++;
        return i == n - 1;
    }
};