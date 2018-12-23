class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        myDict = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        num = 0
        flag = 0
        
        for i in range(len(s)):
            if flag == 1:
                flag = 0
                continue
                
            if len(s) - 1 - i > 0:
                if s[i] == 'I':
                    if s[i+1] == 'V' or s[i+1] == 'X':
                        num += myDict[s[i+1]]-myDict[s[i]]
                        flag = 1
                        continue
                elif s[i] == 'X':
                    if s[i+1] == 'L' or s[i+1] == 'C':
                        num += myDict[s[i+1]]-myDict[s[i]]
                        flag = 1
                        continue
                elif s[i] == 'C':
                    if s[i+1] == 'D' or s[i+1] == 'M':
                        num += myDict[s[i+1]]-myDict[s[i]]
                        flag = 1
                        continue
                        
            num += myDict[s[i]]
        
        return num
