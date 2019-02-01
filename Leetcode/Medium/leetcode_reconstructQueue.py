class Solution:
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        if people == []:
            return []
        
        ans = sorted(people, key = lambda x:x[1])
       
        for i in range(len(ans)):
            if ans[i][1] != 0:
                break
        front = ans[:i]
        front = sorted(front)
        ans = list(front) + ans[i:] #sort by height when people[i][1] is 0

        for i in range(len(ans)):
            if ans[i][1] > 0:
                count = 0
                flag = 0
                for j in range(i):
                    if ans[j][0] >= ans[i][0]:
                        count += 1
                    if count > ans[i][1]:
                        flag = 1
                        break
                
                if flag == 1:
                    ans.insert(j, ans[i])
                    del ans[i+1]
        return ans

"""
python good code)
def reconstructQueue(self, people):
    people.sort(key=lambda x:x[0], reverse=True)
    queue = []
    for p in people:
        queue.insert(p[1], p)
    return queue
"""
