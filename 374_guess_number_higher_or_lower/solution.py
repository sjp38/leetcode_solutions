# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        up = n
        down = 1
        while True:
            mid = (up + down) / 2
            res = guess(mid)
            if res == -1:
                up = mid - 1
            elif res == 1:
                down = mid + 1
            else:
                return mid
