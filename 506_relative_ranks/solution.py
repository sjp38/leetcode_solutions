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
                rank = "%s" % idx
            elif idx == 1:
                rank = "Gold Medal"
            elif idx == 2:
                rank = "Silver Medal"
            else:
                rank = "Bronze Medal"
            ret.append(rank)
        return ret
