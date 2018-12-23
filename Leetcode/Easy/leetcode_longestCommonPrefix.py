class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        flag = 1
        if len(strs) == 0:
            return ""
        
        for string in strs:
            if flag == 1: #처음일때는 리스트에 무조건 저장
                L = list(string)
                flag = 0
                continue
                
            if len(L) == 0:
                return ""
            
            if len(string) < len(L):
                L = L[:len(string)]
                
            for i in range(len(L)):
                if string[i] != L[i]:
                    L = L[:i]
                    break
        
        L = "".join(L)
        return L
    

"""
# python good code))

def longestCommonPrefix(self, strs):
    if not strs:
        return ""
    shortest = min(strs,key=len)
    for i, ch in enumerate(shortest):
        for other in strs:
            if other[i] != ch:
                return shortest[:i]
    return shortest
"""
