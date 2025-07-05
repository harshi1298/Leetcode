#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string hexc(int num)
    {
        if (num == 0)
            return "0";

        string hexDigits = "0123456789ABCDEF";
        string ans = "";
        while (num > 0)
        {
            int remainder = num % 16;
            ans = hexDigits[remainder] + ans;
            num /= 16;
        }

        return ans;
    }
    string hexc36(int num)
    {
        if (num == 0)
            return "0";

        string hexDigits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ans = "";
        while (num > 0)
        {
            int remainder = num % 36;
            ans = hexDigits[remainder] + ans;
            num /= 36;
        }

        return ans;
    }

public:
    string concatHex36(int n)
    {
        int sqr = n * n;
        int cb = n * n * n;
        return hexc(sqr) + hexc36(cb);
    }
};
