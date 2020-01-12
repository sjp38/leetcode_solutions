/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct dyn_nodes {
    struct TreeNode **nodes;
    int cap;
    int nr_nodes;
};

void init_dyn_nodes(struct dyn_nodes *ns, int cap)
{
    ns->cap = cap;
    ns->nodes = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * cap);
    ns->nr_nodes = 0;
}

void append_dyn_nodes(struct dyn_nodes *nodes, struct TreeNode *node)
{
    if (nodes->nr_nodes == nodes->cap) {
        nodes->cap *= 2;
        nodes->nodes = (struct TreeNode **)realloc(nodes->nodes, sizeof(struct TreeNode *) * nodes->cap);
    }
    nodes->nodes[nodes->nr_nodes++] = node;
}

static int next_trav;

void tree_to_nodes(struct TreeNode *node, struct dyn_nodes *arr)
{
    if (!node)
        return;
    append_dyn_nodes(arr, node->left);
    append_dyn_nodes(arr, node->right);
    while (next_trav < arr->nr_nodes) {
        tree_to_nodes(arr->nodes[next_trav++], arr);
    }
}

bool isCompleteTree(struct TreeNode* root){
    struct dyn_nodes nodes;
    int i;
    int last_null_idx;
 
    next_trav = 1;
    init_dyn_nodes(&nodes, 100);
    append_dyn_nodes(&nodes, root);
    tree_to_nodes(root, &nodes);
    for (i = 0, last_null_idx = 0; i < nodes.nr_nodes; i++) {
        if (nodes.nodes[i] == NULL) {
            last_null_idx = i;
            continue;
        }
        if (last_null_idx != 0)
            return false;
    }
    return true;
}
