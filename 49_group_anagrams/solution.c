class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        sdir = {}
        for s in strs:
            key = ''.join(sorted(s))
            if not key in sdir:
                sdir[key] = []
            sdir[key].append(s)
        return sdir.values()
