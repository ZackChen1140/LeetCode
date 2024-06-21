class Solution(object):
    def mergeAlternately(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """
        wordlen = len(word1)
        if len(word2)>wordlen:
            wordlen = len(word2)
        
        merge_word = ''
        for i in range(0, wordlen):
            if i < len(word1):
                merge_word += word1[i]
            if i < len(word2):
                merge_word += word2[i]
        
        return merge_word