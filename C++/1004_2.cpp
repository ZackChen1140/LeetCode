class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> q;
        int max_v = INT_MIN;
        for(auto& n : nums)
        {
            q.emplace(n);
            if(n || k--) continue;
            ++k, max_v = max(max_v, static_cast<int>(q.size() - 1));
            while(!q.empty() && q.front()) q.pop();
            if(!q.empty()) q.pop();
        }
        return max_v = max(max_v, static_cast<int>(q.size()));
    }
};