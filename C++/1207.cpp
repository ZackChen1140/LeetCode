class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_set<int> s;
        for(auto& n : arr) m.count(n) ? ++m[n] : m[n] = 1;
        for(auto& x : m) s.emplace(x.second);
        return m.size() == s.size();
    }
};