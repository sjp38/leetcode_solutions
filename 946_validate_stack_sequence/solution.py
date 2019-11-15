class Solution(object):
    def validateStackSequences(self, pushed, popped):
        """
        :type pushed: List[int]
        :type popped: List[int]
        :rtype: bool
        """
        now_stack = []
        for v in popped:
            while not v in now_stack:
                if len(pushed) == 0:
                    return False
                now_stack.append(pushed[0])
                pushed = pushed[1:]
            if not v == now_stack[-1]:
                return False
            now_stack = now_stack[:-1]
        return True
