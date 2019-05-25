class Solution(object):
    def toGoatLatin(self, S):
        """
        :type S: str
        :rtype: str
        """
        words = S.split()
        for i, w in enumerate(words):
            if w[0] in ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']:
                w += "ma"
            else:
                w = w[1:] + w[0] + "ma"
            w += "a" * (i + 1)
            words[i] = w
        return ' '.join(words)
