class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0, sum = 0;
        auto it1 = nums.begin(), it2 = nums.end() - 1;
        while(it1 < it2) (sum = *it1 + *it2) == k ? ++cnt, ++it1, --it2 : (sum > k ? --it2 : ++it1);
        return cnt;
    }
};