# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        
        point = head
        len_head = 1
        while(1):
            if point.next == None:
                break
            point = point.next
            len_head += 1
        
        if n == len_head: #delete first one
            return head.next
        
        point = head
        num = 1
        while(1):
            if len_head - num == n:
                break
            point = point.next
            num += 1
        
        erase = point.next
        point.next = erase.next
        erase.next = None
        
        return head

"""
python good solution; 전체 길이를 구하지 않고 포인터 두개 이용))

class Solution:
    def removeNthFromEnd(self, head, n):
        fast = slow = head
        for _ in range(n):
            fast = fast.next
        if not fast:
            return head.next
        while fast.next:
            fast = fast.next
            slow = slow.next
        slow.next = slow.next.next
        return head
"""
