def is_valid(nrs, idx):
    # returns whether left and right node exists, and the idx of right child.
    if len(nrs) <= idx:
        return False, -1
    if nrs[idx] == '#':
        return True, idx + 1
    
    lcidx = idx + 1
    valid, ridx = is_valid(nrs, lcidx)
    if not valid:
        return False, -1
    valid, ridx = is_valid(nrs, ridx)
    if not valid:
        return False, -1
    return True, ridx

class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        nrs = preorder.split(',')
        valid, ridx = is_valid(nrs, 0)
        if ridx == len(nrs):
            return True
        return False
