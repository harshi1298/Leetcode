class Solution {
public:
    string pushDominoes(string d) {
        int n = d.size();
        vector<int> left_forces(n, 0), right_forces(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (d[i] == 'R') {
                count = n; 
            } else if (d[i] == 'L') {
                count = 0;
            } else if (count > 0) {
                count--;
            }
            right_forces[i] = count;
        }
        count = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (d[i] == 'L') {
                count = n; // Maximum force applied
            } else if (d[i] == 'R') {
                count = 0; // No force after a 'R'
            } else if (count > 0) {
                count--; // Decrease force as we move away from 'L'
            }
            left_forces[i] = count;
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (right_forces[i] > left_forces[i]) {
                ans += 'R'; // Right force is stronger
            } else if (left_forces[i] > right_forces[i]) {
                ans += 'L'; // Left force is stronger
            } else {
                ans += '.'; // No force, remains upright
            }
        }

        return ans;
    }
};
