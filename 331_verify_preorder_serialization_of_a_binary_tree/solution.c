char *nextnode(char *node)
{
    for (node += 1; *node != '\0'; node++) {
        if (*node == ',')
            return &node[1];
    }
    return node;
}

char *sibling(char *node)
{
    char *left, *right;
    int right_child;
    if (*node == '\0')
        return NULL;
    if (*node == '#')
        return nextnode(node);
    left = nextnode(node);
    right = sibling(left);
    if (right == NULL)
        return NULL;
    return sibling(right);
}

bool isValidSerialization(char * preorder){
    if (*preorder == '\0')
        return true;
    preorder = sibling(preorder);
    if (preorder == NULL || *preorder != '\0')
        return false;
    return true;
}
