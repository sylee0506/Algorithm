class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        ans = 0

        while len(height) != 0:
            width = len(height) - 1
            tmp = width * min(height[0], height[width])
            
            if ans < tmp:
                ans = tmp
                
            if height[0] >= height[width]:
                height = height[:width]
            else:
                height = height[1:]
        
        return ans
