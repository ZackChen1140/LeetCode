class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> acv = nums;
        nums.emplace(nums.begin(), 0), acv.emplace_back(0);
        for(int i = nums.size() - 2; i >= 0; --i) acv[i] += acv[i + 1];
        for(int i = 1; i < nums.size(); ++i)
            if(acv[i - 1] == (nums[i] += nums[i - 1])) return i - 1;
        return -1;
    }
};