# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

def trav(node, lv, lvmap):
    if not node:
        return
    trav(node.left, lv + 1, lvmap)
    trav(node.right, lv + 1, lvmap)
    if not lv in lvmap:
        lvmap[lv] = []
    lvmap[lv].append(node.val)
    
class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        lvmap = {}
        trav(root, 0, lvmap)
        ret = []
        for lv in sorted(lvmap.keys(), reverse=True):
            ret.append(lvmap[lv])
        return ret
