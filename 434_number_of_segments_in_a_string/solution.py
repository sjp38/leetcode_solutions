class Solution(object):
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        nr = 0
        prev = " "
        for c in s:
            if prev == " " and c != " ":
                nr += 1
        prev = c
        return nr
