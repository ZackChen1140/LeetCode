class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (!n) return;
        if (!m)
        {
            nums1 = nums2;
            return;
        }

        while (nums1[nums1.size() - 1] == 0 && nums1.size() > m) nums1.pop_back();
        while (nums2[nums2.size() - 1] == 0 && nums2.size() > n) nums2.pop_back();
        
        vector<int> v;
        int i = 0;
        int j = 0;

        while(v.size() < m + n)
        {
            if (i < nums1.size())
            {
                if (j < nums2.size()) v.push_back(nums1[i] < nums2[j] ? nums1[i++] : nums2[j++]);
                else v.push_back(nums1[i++]);
            }
            else v.push_back(nums2[j++]);
        }
        nums1 = v;
    }
};