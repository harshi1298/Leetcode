class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;
        int oddCount = 0;
        char middleChar = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                oddCount++;
                if (middleChar == 0 || i + 'a' < middleChar) {
                    middleChar = i + 'a';  
                }
            }
        }
        if (oddCount > 1) return "";
        string half = "";
        for (int i = 0; i < 26; ++i) {
            int times = count[i] / 2;
            half += string(times, i + 'a');
        }
        string revHalf = half;
        reverse(revHalf.begin(), revHalf.end());
        
        if (middleChar)
            return half + middleChar + revHalf;
        else
            return half + revHalf;
    }
};
