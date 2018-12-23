class Solution:
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        myDict = {}
        index = 0
        for char in s:
            if char in myDict:
                myDict[char] = -1
            else:
                myDict[char] = index
            index += 1
            
        L = []
        for key in myDict.keys():
            if int(myDict[key]) != -1:
                L.append(int(myDict[key]))
        
        if len(L) == 0:
            return -1
        else:
            L.sort()
            return L[0]
        
