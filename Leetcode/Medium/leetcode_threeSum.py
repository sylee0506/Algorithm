class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) == 0:
            return []
        
        sol = []
        nums.sort()
        
        for i in range(len(nums)-2):
            if i>0 and nums[i] == nums[i-1]:
                continue
            
            left = i+1
            right = len(nums)-1
            
            while left < right:
                sum3 = nums[i]+nums[left]+nums[right]
            
                if sum3 > 0:
                    right = right-1
                elif sum3 < 0:
                    left = left+1
                elif sum3 == 0:
                    sol.append([nums[i], nums[left], nums[right]])
                    while left < right and nums[left] == nums[left+1]:
                        left = left+1
                    while left < right and nums[right] == nums[right-1]:
                        right = right-1
                    left += 1
                    right -=1
                    
        return sol
