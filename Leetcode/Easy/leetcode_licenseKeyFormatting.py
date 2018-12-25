"""
It was a demo question of Google coding sample!!!!
"""


class Solution:
    def licenseKeyFormatting(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        total = S.replace("-","")
        ans = ""
        num = 1
    
        for i in range(len(total)):
            ans = ans + total[len(total)-1-i]
            if num % K == 0 and i != len(total)-1:
                ans += '-'
            num +=1
    
        ans = ans.upper()
        ans = ans[::-1]
        return ans
