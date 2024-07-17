class Solution {
public:
    string removeStars(string s) {
        string rs = "";
        for(auto& c : s)
        {
            if(c == '*') rs.pop_back();
            else rs += c;
        }
        return rs;
    }
};