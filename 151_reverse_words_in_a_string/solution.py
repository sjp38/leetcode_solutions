class Solution(object):
    def reverseWords(self, s):
    """
    :type s: str
    :rtype: str
    """
    words = s.split()
    answer = []
    for w in words:
        answer = [w] + answer
    return " ".join(answer)
