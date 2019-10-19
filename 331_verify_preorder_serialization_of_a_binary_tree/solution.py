def is_valid(nodes, idx):
    # returns validity of the node and the idx of the sibling node.
    if len(nodes) <= idx:
        return False, -1
    if nodes[idx] == '#':
        return True, idx + 1
    
    lidx = idx + 1
    valid, ridx = is_valid(nodes, lidx)
    if not valid:
        return False, -1
    valid, nidx = is_valid(nodes, ridx)
    if not valid:
        return False, -1
    return True, nidx

class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        nodes = preorder.split(',')
        valid, nr_nodes = is_valid(nodes, 0)
        if nr_nodes == len(nodes):
            return True
        return False
