'''
Leetcode Medium: 56. Merge Intervals
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
'''

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        output = []

        intervals = sorted(intervals, key=lambda x: x[0])

        for interval in intervals:
            if not output or output[-1][1] < interval[0]:
                output.append(interval)
            else:
                output[-1][1] = max(output[-1][1], interval[1])

        return output

'''
# Python code using stack
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x:x[0])
        stack=[]
        for i in range(0,len(intervals)):
            if stack and stack[0][1]>=intervals[i][0]:
                stack[0][1]=max(stack[0][1],intervals[i][1])
            else:
                stack.insert(0,intervals[i])
        return stack
'''