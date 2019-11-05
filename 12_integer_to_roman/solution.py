# digit = 0-9
def get_roman(digit, base):
    romans = 'IVX'
    if base == 10:
        romans = ['X', 'L', 'C']
    elif base == 100:
        romans = ['C', 'D', 'M']
    elif base == 1000:
        romans = ['M']
    if digit < 4:
        return romans[0] * digit
    if digit == 4:
        return romans[0] + romans[1]
    if digit < 9:
        return romans[1] + romans[0] * (digit - 5)
    if digit == 9:
        return romans[0] + romans[2]

class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        ret = ""
        base = 1
        while num:
            digit = num % 10
            ret = get_roman(digit, base) + ret
            base *= 10
            num /= 10
        return ret
