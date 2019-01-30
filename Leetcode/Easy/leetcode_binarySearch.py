class Solution:
    def binarySearch(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        left = 0
        right = len(nums) - 1
        
        while left <= right:
            middle = (left + right) // 2
            
            if target == nums[middle]:
                return middle
            elif target > nums[middle]:
                left = middle + 1
            elif target < nums[middle]:
                right = middle - 1
        
        return -1
