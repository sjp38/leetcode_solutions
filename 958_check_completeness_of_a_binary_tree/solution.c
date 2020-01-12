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
static bool met_null;

bool trav(struct TreeNode *node, struct dyn_nodes *arr)
{
    if (!node) {
        met_null = true;
        return true;
    }
    if (met_null)
        return false;
    
    append_dyn_nodes(arr, node->left);
    append_dyn_nodes(arr, node->right);
    while (next_trav < arr->nr_nodes) {
        if (!trav(arr->nodes[next_trav++], arr))
            return false;
    }
    return true;
}

bool isCompleteTree(struct TreeNode* root){
    struct dyn_nodes nodes;
    int i;
    int last_null_idx;
 
    next_trav = 0;
    met_null = false;
    init_dyn_nodes(&nodes, 100);
    return trav(root, &nodes);
}
