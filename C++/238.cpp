class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_num = count(nums.begin(), nums.end(), 0), accum = 1;
        for(auto& n : nums) if(n) accum *= n;
        for(auto& n : nums) n = zero_num ? (zero_num == 1 ? (n ? 0 : accum) : 0) : (accum/n);
        return nums;
    }
};