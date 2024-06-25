class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        if(unordered_set<int>(nums.begin(), nums.end()).size() < 3) return false;
        for(auto it = nums.begin() + 1; it != nums.end() - 1; ++it)
            if(*min_element(nums.begin(), it) < *it && *max_element(it + 1, nums.end()) > *it)
                return true;
        return false;
    }
};