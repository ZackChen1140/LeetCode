class Solution {
public:
    string decodeString(string s) {
        if(s.find("[")==string::npos) return s;
        int ki, idx;
        string k, result, subresult;
        stack<int> ls;
        for(int i = 0; i < s.length(); ++i)
        {
            if(s[i] >= '0' && s[i] <= '9') k += s[i];
            else if(s[i] == '[')
            {
                idx = i + 1, ki = stoi(k), k.clear(), ls.push(0);
                while(!ls.empty())
                {
                    if(s[++i] == '[') ls.push(0);
                    if(s[i] == ']') ls.pop();
                }
                subresult = decodeString(s.substr(idx, i - idx));
                while(ki--) result += subresult;
            }
            else result += s[i];
        }
        return result;
    }
};