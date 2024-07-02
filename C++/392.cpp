class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto sit = s.begin(), tit = t.begin();
        while(sit != s.end() && tit != t.end()) if(*sit == *tit++) ++sit;
        return sit == s.end();
    }
};