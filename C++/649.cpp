class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r, d;
        int len = senate.length();
        for(int i = 0; i < senate.length(); ++i)
        {
            if(senate[i] == 'R') r.push(i);
            else d.push(i);
        }
        while(!r.empty() && !d.empty())
        {
            if(r.front() < d.front()) d.pop(), r.push(++len), r.pop();
            else r.pop(), d.push(++len), d.pop();
        }
        return r.empty() ? "Dire" : "Radiant";
    }
};