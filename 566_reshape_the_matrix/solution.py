class Solution(object):
    def matrixReshape(self, nums, r, c):
        """
        :type nums: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        nr_rows = len(nums)
        if nr_rows == 0:
            return nums
        nr_cols = len(nums[0])
        if r * c != nr_rows * nr_cols:
            return nums
        rows = []
        for i in range(r):
            row = []
            for j in range(c):
                row.append(nums[(c * i + j) / nr_cols][(c * i + j) % nr_cols])
            rows.append(row)
        return rows
