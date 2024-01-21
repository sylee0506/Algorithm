'''
Leetcode Easy: 9. Palindrome Number
Given an integer x, return true if x is a palindrome, and false otherwise.
'''

class Solution:
    def isPalindrome(self, x: int) -> bool:
        strX = str(x)
        leftIdx = 0
        rightIdx = len(strX) - 1

        while leftIdx <= rightIdx:
            if strX[leftIdx] != strX[rightIdx]:
                return False
            leftIdx += 1
            rightIdx -= 1

        return True

'''
# good & fast Python code
class Solution:
    def isPalindrome(self, x: int) -> bool:
        x = str(x)
        return x[::-1] == x
'''