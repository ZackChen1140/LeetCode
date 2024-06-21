class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int maxlen = word1.length() > word2.length() ? word1.length() : word2.length();
        string merged_word = "";
        for(int i = 0 ; i < maxlen ; ++i)
        {
            if(i < word1.length()) merged_word += word1[i];
            if(i < word2.length()) merged_word += word2[i];
        }
        return merged_word;
    }
};