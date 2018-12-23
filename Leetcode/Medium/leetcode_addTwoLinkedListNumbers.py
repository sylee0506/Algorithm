# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        result = ListNode(0)
        head = result
        add_flag = 0
        
        while(l1 or l2):            
            node = ListNode(0)
            
            if not l1:
                l1 = node
            elif not l2:
                l2 = node
                
            node.val = l1.val + l2.val + add_flag
            
            if node.val >= 10:
                add_flag = 1
                node.val -= 10
            else:
                add_flag = 0
            
            l1 = l1.next
            l2 = l2.next
            result.next = node
            result = result.next
            
            if not l1 and not l2 and add_flag == 1:
                node = ListNode(0)
                node.val = 1
                result.next = node          
                  
        return head.next

"""
python good code)

class Solution:
# @return a ListNode
def addTwoNumbers(self, l1, l2):
    carry = 0
    root = n = ListNode(0)
    while l1 or l2 or carry:
        v1 = v2 = 0
        if l1:
            v1 = l1.val
            l1 = l1.next
        if l2:
            v2 = l2.val
            l2 = l2.next
        carry, val = divmod(v1+v2+carry, 10)
        n.next = ListNode(val)
        n = n.next
    return root.next

"""
