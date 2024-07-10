class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0, max_v = INT_MIN, k = 1;
        while(r < nums.size())
        {
            if(nums[r++]) continue;
            if(k-- == 0)
            {
                ++k, max_v = max(max_v, r - l - 2);
                while(l < nums.size() && nums[l++] == 1);
            }
        }
        return max_v = max(max_v, r - l - 1);
    }
};