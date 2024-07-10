class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero = 0, max_v = INT_MIN;
        queue<int> q;
        for(auto& n : nums)
        {
            q.emplace(n);
            if(n || !zero++) continue;
            --zero, max_v = max(max_v, static_cast<int>(q.size()) - 2);
            while(!q.empty() && q.front()) q.pop();
            if(!q.empty()) q.pop();
        }
        return max_v = max(max_v, static_cast<int>(q.size()) - 1);
    }
};