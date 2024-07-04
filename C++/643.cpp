class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        for(int i = 1; i < k ; ++i) nums[i] += nums[i - 1];
        int max_v = nums[k - 1];
        for(int i = k; i < nums.size(); ++i) max_v = max(max_v, (nums[i] += nums[i - 1]) - nums[i - k]);
        return (double)max_v / k;
    }
};