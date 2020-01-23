# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

deepest_nodes = []
deepest_depth = 0

def add_deepest_nodes(node, depth):
    global deepest_nodes
    global deepest_depth
    
    if not node:
        return
    add_deepest_nodes(node.left, depth + 1)
    add_deepest_nodes(node.right, depth + 1)
    if depth == deepest_depth:
        deepest_nodes.append(node)
    elif depth > deepest_depth:
        deepest_depth = depth
        deepest_nodes = [node]
    
def answer(node, depth):
    if not node:
        return node
    if depth == deepest_depth:
        return node
    la = answer(node.left, depth + 1)
    ra = answer(node.right, depth + 1)
    if la and ra:
        return node
    if la:
        return la
    if ra:
        return ra
    
class Solution(object):
    def subtreeWithAllDeepest(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        global deepest_nodes
        global deepest_depth
        deepest_nodes = []
        deepest_depth = 0
        add_deepest_nodes(root, 0)
        return answer(root, 0)
