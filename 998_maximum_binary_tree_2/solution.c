/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static struct TreeNode *new_node(int val)
{
    struct TreeNode *node;
    node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/*
if the val is larger than the root, it should be the root, and prev root becomes its left child.
if the val is larger than a node, it should be replaced with the val.  the prev subtree should be its left tree.
*/

struct TreeNode* insertIntoMaxTree(struct TreeNode* root, int val){
    struct TreeNode **link, *node, *newnode;
    newnode = new_node(val);
    if (!root || val > root->val) {
        newnode->left = root;
        return newnode;
    }
        
    node = root;
    link = &root;
    while (node) {
        if (node->val < val) {
            newnode->left = node;
            *link = newnode;
            return root;
        }
        link = &node->right;
        node = node->right;
    }
    *link = newnode;
    return root;
}
