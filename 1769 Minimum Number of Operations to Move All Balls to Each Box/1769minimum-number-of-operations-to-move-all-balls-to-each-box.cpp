class Solution {
public:
    vector<int> minOperations(string boxes) {
        int l = boxes.length();
        vector<int> ans(l, 0);
        int rightone = 0, leftone = 0, count = 0, count2 = 0;
        for (int i = l - 1; i >= 0; i--) {
            if (boxes[i] == '1') {
                count++;
            }
            rightone += count;
        }
        for (int i = 0; i < l; i++) {
            ans[i] = rightone - count + leftone;
            if (boxes[i] == '1') {
                count--;
            }
            leftone += count2;
            if (boxes[i] == '1') {
                count2++;
            }
            rightone -= count;
        }

        return ans;
    }
};
