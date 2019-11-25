class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        sorted_ranks = sorted(nums, reverse=True)
        ret = []
        for nr in nums:
            idx = sorted_ranks.index(nr) + 1
            if idx > 3:
                ret.append("%s" % idx)
            elif idx == 1:
                ret.append("Gold Medal")
            elif idx == 2:
                ret.append("Silver Medal")
            else:
                ret.append("Bronze Medal")
        return ret
