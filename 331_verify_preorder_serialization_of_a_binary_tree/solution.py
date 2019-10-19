def sibling(nodes, idx):
    # returns the idx of the sibling node, -1 if it the node is invalid.
    if len(nodes) <= idx:
        return -1
    if nodes[idx] == '#':
        return idx + 1
    # left child
    ridx = sibling(nodes, idx + 1)
    if ridx == -1:
        return -1
    # right child
    nidx = sibling(nodes, ridx)
    if nidx == -1:
        return -1
    return nidx

class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        nodes = preorder.split(',')
        nr_nodes = sibling(nodes, 0)
        if nr_nodes == len(nodes):
            return True
        return False
