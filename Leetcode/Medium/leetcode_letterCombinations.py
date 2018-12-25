class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        myDict = {'2':['a','b','c'], '3':['d','e','f'], '4':['g','h','i'], '5':['j','k','l'], '6':['m','n','o'], '7':['p','q','r','s'], '8':['t','u','v'], '9':['w','x','y','z']}
        stack = []
        
        for i in range(len(digits)):
            if i == 0:
                stack = list(myDict[digits[i]])
                continue
            
            stack2 = []
            while len(stack):
                word = stack.pop()
                for k in range(len(myDict[digits[i]])):
                    stack2.append(word + myDict[digits[i]][k])
            
            stack = stack2
        
        return stack
