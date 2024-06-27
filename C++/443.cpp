class Solution {
public:
    int compress(vector<char>& chars) {
        queue<pair<char, int>> q;
        while(!chars.empty())
        {
            if(q.empty() || *chars.begin() != q.back().first) q.emplace(*chars.begin(), 0);
            ++q.back().second, chars.erase(chars.begin());
        }
        while(!q.empty())
        {
            chars.emplace_back(q.front().first);
            if(q.front().second - 1) for(char c : to_string(q.front().second)) chars.emplace_back(c);
            q.pop();
        }
        return chars.size();
    }
};