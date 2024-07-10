class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end());
        vector<vector<int>> answer(2, vector<int>());
        for(auto& n : s1) if(!s2.contains(n)) answer[0].emplace_back(n);
        for(auto& n : s2) if(!s1.contains(n)) answer[1].emplace_back(n);
        return answer;
    }
};