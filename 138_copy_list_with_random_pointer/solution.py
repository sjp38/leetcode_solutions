"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if not head:
            return None
        copies = {}
        orig_head = head
        while head:
            copy = Node(head.val, head.next, head.random)
            copies[head] = copy
            head = head.next
        for copy in copies.values():
            if copy.next:
                copy.next = copies[copy.next]
            if copy.random:
                copy.random = copies[copy.random]
        return copies[orig_head]
