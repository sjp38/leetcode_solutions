morse_codes = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
class Solution(object):
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        concats = {}
        for w in words:
            concat = ''
            for c in w:
                concat += morse_codes[ord(c) - ord('a')]
            concats[concat] = True
        return len(concats)
