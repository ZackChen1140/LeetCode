class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        rs = ''
        words = list(filter(lambda x : x != '', s.split(' ')))
        words.reverse()
        for word in words:
            rs += (word.strip() + ' ')
        return rs[:-1]