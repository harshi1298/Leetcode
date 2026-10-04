class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        res = 0
        j = 0
        fre = {}
        for i in range(0,n):
            fre[s[i]] = fre.get(s[i],0) + 1
            while fre[s[i]] >= 2 :
                fre[s[j]] -= 1
                j += 1
            res = max(res,i-j+1)   
        return res
