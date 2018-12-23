class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        #nums.sort()
        myDict = {}
        ans = []
        
        for i in range(len(nums)):
            #if(nums[i] > target):
                #continue
            #else:
                for key in myDict.keys():
                    if (key + nums[i]) == target:
                        ans.append(myDict[key])
                        ans.append(i)
                        ans.sort()
                        return ans
                myDict[nums[i]] = i

"""
시간복잡도 O(n) 풀이

class Solution(object):
    def twoSum(self, nums, target):
        if len(nums) <= 1:
            return False
        buff_dict = {}
        for i in range(len(nums)):
            if nums[i] in buff_dict:
                return [buff_dict[nums[i]], i]
            else:
                buff_dict[target - nums[i]] = i
"""
