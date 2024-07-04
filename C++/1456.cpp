class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u'};
        int sum = 0, max_v;
        for(int i = 0; i < k; ++i) max_v = (sum += v.contains(s[i]));
        for(int i = k; i < s.length(); ++i)
            if((max_v = max(max_v, sum += (v.contains(s[i]) - v.contains(s[i - k])))) == k)
                return k;
        return max_v;
    }
};