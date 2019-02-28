/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* next;
	struct ListNode* node = NULL;
	while (head)
	{
		next = head->next;
		head->next = node;
		node = head;
		head = next;
	}
	return node;
}