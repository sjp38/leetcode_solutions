/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int answer;
struct TreeNode **parents;
int nr_parents;
int cap_parents;

int add_parent(struct TreeNode *node)
{
    if (nr_parents == cap_parents) {
        cap_parents *= 2;
        parents = (struct TreeNode **)realloc(parents, sizeof(struct TreeNode *) * cap_parents);
        if (!parents)
            return -1;
    }
    parents[nr_parents++] = node;
    return 0;
}

void trav(struct TreeNode *node, int target, int parent_sum)
{
    int sum;
    int i;
    
    if (!node)
        return;
    
    sum = parent_sum + node->val;
    if (sum == target)
        answer++;
    for (i = 0; i < nr_parents; i++) {
        sum -= parents[i]->val;
        if (sum == target)
            answer++;
    }
    
    if (add_parent(node)) {
        printf("failed to add parent!\n");
        exit(-1);
    }
    trav(node->left, target, parent_sum + node->val);
    trav(node->right, target, parent_sum + node->val);
    
    nr_parents--;
}

int pathSum(struct TreeNode* root, int sum){
    answer = 0;
    cap_parents = 10;
    parents = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * cap_parents);
    nr_parents = 0;
    
    trav(root, sum, 0);
    return answer;
}
