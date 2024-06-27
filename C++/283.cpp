class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto it1 = nums.begin(), it2 = nums.begin();
        while(it2 != nums.end())
        {
            while(it1 != nums.end() && *it1 != 0) if(it2 == it1++) ++it2;
            while(it2 != nums.end() && *it2 == 0) ++it2;
            if(it2 != nums.end()) swap(*it1, *it2);
        }
    }
};