class Solution {
public:
    string reverseVowels(string s) {
        vector<char> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        auto it1 = s.begin(), it2 = --s.end();
        while(it2 > it1)
        {
            while(find(v.begin(), v.end(), *it1) == v.end() && it1 < it2) ++it1;
            while(find(v.begin(), v.end(), *it2) == v.end() && it2 > it1) --it2;
            swap(*it1++, *it2--);
        }
        return s;
    }
};