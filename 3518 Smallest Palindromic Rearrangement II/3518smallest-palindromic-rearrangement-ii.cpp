class Solution {
private:
    typedef long long ll;
    ll ncr(int n,int r,int k){
       if(r>n-r){
        r=n-r;
       }
       ll x1=1;
       for(int i=1;i<=r;i++){
         x1=(x1*(n-r+i))/i;
         if(x1>=k)return x1;
       }
       return x1;
    }
    ll countPalindromes(const vector<int>& halfCount,int k) {
        ll total = 0, res = 1;
        for (int c : halfCount) total += c;
        for (int c : halfCount) {
           if(c>0){
            res*=ncr(total,c,k);
            total-=c;
           }
           if(res>=k)return res;
        }
        return res;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<int> halfFreq(26, 0);
        int oddCount = 0;
        char middleChar = 0;

        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2) {
                ++oddCount;
                middleChar = 'a' + i;
            }
            halfFreq[i] = freq[i] / 2;
        }

        if (oddCount > 1) return "";  

        string leftPart = "";
        ll totalHalfLen = accumulate(halfFreq.begin(), halfFreq.end(), 0LL);

        while (totalHalfLen > 0) {
            bool found = false;
            for (int i = 0; i < 26; ++i) {
                if (halfFreq[i] == 0) continue;
                halfFreq[i]--;
                ll count = countPalindromes(halfFreq,k);
                if (count >= k) {
                    leftPart += ('a' + i);
                    found = true;
                    break;
                } else {
                    k -= count;
                    halfFreq[i]++;
                }
            }
            if (!found) return ""; 
            totalHalfLen--;
        }

        string rightPart(leftPart.rbegin(), leftPart.rend());
        if (oddCount == 1) leftPart += middleChar;
        return leftPart + rightPart;
    }
};
