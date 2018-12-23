class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        myDict = {'(' : ')', '{' : '}', '[' : ']'}
        stack = []
        
        for char in s:
            if char in myDict:
                stack.append(char)
            else:
                if len(stack) == 0:
                    return False
                if myDict[stack.pop()] != char:
                    return False
        
        if len(stack) == 0:
            return True
        else:
            return False
