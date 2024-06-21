class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        stk.emplace("");
        for(auto& ch : s)
        {
            if(ch != ' ') stk.top() += ch;
            else if(stk.top() != "") stk.emplace("");
        }
        if(stk.top() == "") stk.pop();
        string rs = "";
        while(!stk.empty()) rs += (stk.top() + ' '), stk.pop();
        return rs.substr(0, rs.length() - 1);
    }
};