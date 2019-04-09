void addRow(struct TreeNode *node, int v, int d, int nowdepth)
{
	struct TreeNode *orig_l, *orig_r;
	struct TreeNode *newl, *newr;

	if (node == NULL)
		return;
	if (nowdepth != d - 1) {
		addRow(node->left, v, d, nowdepth + 1);
		addRow(node->right, v, d, nowdepth + 1);
		return;
	}

	orig_l = node->left;
	orig_r = node->right;

	newl = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	newl->val = v;
	newl->left = orig_l;
	newl->right = NULL;

	newr = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	newr->val = v;
	newr->right = orig_r;
	newr->left = NULL;

	node->left = newl;
	node->right = newr;
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* addOneRow(struct TreeNode* root, int v, int d) {
	struct TreeNode *newroot;

	if (d == 1) {
		newroot = (struct TreeNode *)malloc(sizeof(struct TreeNode));
		newroot->val = v;
		newroot->left = root;
		newroot->right = NULL;
		return newroot;
	}

	addRow(root, v, d, 1);
	return root;
}
