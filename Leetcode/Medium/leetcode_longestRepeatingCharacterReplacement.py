'''
Leetcode Medium: 424. Longest Repeating Character Replacement
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.
'''

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        # algorithm) sliding window + two pointers
        result = 0
        left = right = 0
        freqCount = {}

        for right in range(len(s)):
            windowSize = right - left + 1

            if s[right] in freqCount:
                freqCount[s[right]] += 1
            else:
                freqCount[s[right]] = 1

            # maxFreqCount = sorted(freqCount.items(), key=lambda x: x[1])[-1][1]
            maxFreqCount = max(freqCount.values())
            replacementCost = windowSize - maxFreqCount

            if replacementCost <= k:
                if windowSize > result:
                    result = windowSize
            else:
                freqCount[s[left]] -= 1
                left += 1

        return result