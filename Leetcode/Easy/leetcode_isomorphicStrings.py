'''
Leetcode Easy: 205. Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
'''

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        myDict = {}
        for i in range(len(s)):
            # if s[i] == t[i]:
                # continue
            # else:
                if s[i] in myDict:
                    if myDict[s[i]] != t[i]:
                        return False
                else:
                    if t[i] in myDict.values():
                        return False
                    myDict[s[i]] = t[i]
        
        return True

'''
# good & fast Python code
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        dic_s = {char:index for index, char in enumerate(s)}
        dic_t = {char:index for index, char in enumerate(t)}

        return list(dic_s.values()) == list(dic_t.values())
'''