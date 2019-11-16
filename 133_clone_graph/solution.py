"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors
"""
def add_node_neighbors(node, nodes):
    if node.val in nodes:
        return
    nodes[node.val] = node
    for n in node.neighbors:
        add_node_neighbors(n, nodes)

class Solution(object):
    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        orig_nodes = {}
        add_node_neighbors(node, orig_nodes)
        new_nodes = {}
        for v in orig_nodes:
            new_nodes[v] = Node(v, [])
        for v in orig_nodes:
            orig_node = orig_nodes[v]
            new_node = new_nodes[v]
            for nn in orig_node.neighbors:
                new_node.neighbors.append(new_nodes[nn.val])
        return new_nodes[node.val]
