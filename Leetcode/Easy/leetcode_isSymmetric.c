/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool solve(struct TreeNode* left, struct TreeNode* right)
{
	if (!left && !right)
		return true;
	else if (!left || !right)
		return false;

	if (left->val != right->val)
		return false;
	else
		return solve(left->left, right->right) && solve(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
	if (!root)
		return true;
	return solve(root->left, root->right);
}