class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0:
            return 0
        
        if len(s) == 1:
            return 1
        
        ans = []
        sub_str = ""
        for i in range(len(s)):
            if len(sub_str) == 0:
                sub_str += s[i]
                continue
                    
            if s[i] not in sub_str:
                sub_str += s[i]
            else:
                ans.append(len(sub_str))
                sub_str = sub_str[sub_str.find(s[i])+1:]
                sub_str += s[i]
                    
        ans.append(len(sub_str))
            
        return max(ans)
