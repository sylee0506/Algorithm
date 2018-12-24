class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        ans = ""
        
        for i in range(len(s)):
            tmp = ""
            tmp = self.solve(s, i, i+1) #회문이 짝수개일때
            if len(tmp) > len(ans):
                ans = tmp
            tmp = self.solve(s, i, i)   #회문이 홀수개일때            
            if len(tmp) > len(ans):
                ans = tmp
        
        return ans
    
    def solve(self, s, l, r):
        while (l >= 0) and (r < len(s)) and (s[l] == s[r]):
            l = l-1
            r = r+1
        return s[l+1:r]
