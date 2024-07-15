class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;
        vector<int> v1(26, 0), v2(26, 0);
        set<char> s1, s2;
        for(int i = 0; i < word1.length(); ++i)
        {
            if(!s1.contains(word1[i])) s1.emplace(word1[i]);
            if(!s2.contains(word2[i])) s2.emplace(word2[i]);
            ++v1[word1[i] - 'a'], ++v2[word2[i] - 'a'];
        }
        if(s1 != s2) return false;
        sort(v1.begin(), v1.end()), sort(v2.begin(), v2.end());
        return v1 == v2;
    }
};