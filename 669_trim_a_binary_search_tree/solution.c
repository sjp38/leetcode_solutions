/*
 * node     node to remove
 * parent   parent of the node
 * root     root of this tree
 *
 * Returns root of this tree after the removal.
 */
struct TreeNode *bst_remove(struct TreeNode *node, struct TreeNode *parent, struct TreeNode *root) {
	printf("remove %d\n", node->val);
	struct TreeNode **to_node = NULL;
	struct TreeNode *prev, **to_prev;

	if (parent && parent->left == node)
		to_node = &parent->left;
	else if (parent)
		to_node = &parent->right;

	/* If leaft node, just nullify the pointer to the node */
	if (!node->left && !node->right) {
		if (to_node) {
			*to_node = NULL;
			return root;
		}
		return NULL;
	}

	if (!node->left) {
		if (to_node) {
			*to_node = node->right;
			return root;
		}
		return node->right;
	}
	if (!node->right) {
		if (to_node) {
			*to_node = node->left;
			return root;
		}
		return node->left;
	}

	/* find in-order predecessor of the node */
	for (to_prev = &node->left, prev = node->left; prev->right; to_prev = &prev->right, prev = prev->right)
		;
	node->val = prev->val;
	if (!prev->left) {
		*to_prev = NULL;
		return root;
	}

	*to_prev = prev->left;
	return root;
}

struct TreeNode *__trim_bst(struct TreeNode *root, struct TreeNode *node, struct TreeNode *parent, int L, int R) {
	if (node == NULL)
		return root;

	root = __trim_bst(root, node->left, node, L, R);
	root = __trim_bst(root, node->right, node, L, R);

	if (node->val < L || node->val > R)
		root = bst_remove(node, parent, root);
	return root;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* trimBST(struct TreeNode* root, int L, int R) {
	return __trim_bst(root, root, NULL, L, R);
}
