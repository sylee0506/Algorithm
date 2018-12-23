/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* head = result;

	while (1)
	{
		if (l1 == NULL)
		{
			result->next = l2;
			break;
		}
		else if (l2 == NULL)
		{
			result->next = l1;
			break;
		}
		else
		{
			if (l1->val <= l2->val)
			{
				result->next = l1;
				l1 = l1->next;
			}
			else
			{
				result->next = l2;
				l2 = l2->next;
			}
		}
		result = result->next;
	}
	return(head->next);
}

/*
python«Æ¿Ã

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

def mergeTwoLists1(self, l1, l2) :
	dummy = cur = ListNode(0)
	while l1 and l2 :
		if l1.val < l2.val :
			cur.next = l1
			l1 = l1.next
		else :
			cur.next = l2
			l2 = l2.next
			cur = cur.next
			cur.next = l1 or l2
			return dummy.next

*/