morse_codes = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
class Solution(object):
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        concats = {}
        for w in words:
            codes = []
            for c in w:
                codes.append(morse_codes[ord(c) - ord('a')])
            concats[''.join(codes)] = True
        return len(concats)
