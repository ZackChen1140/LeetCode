class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) 
    {
        if(k == 1 && nums.size() > 1) return true;
        auto it1 = nums.begin(), it2 = nums.begin() + 1, itm = it1;
        int adj_num = 0;
        while(it2 < nums.end())
        {
            if(*it2 <= *(it2 - 1))
            {
                if(adj_num == 1) --adj_num, it2 = itm;
                it1 = it2;
            }
            else if(it2 - it1 + 1 == k) itm = (it1 + 1), ++adj_num, it1 = ++it2;
            ++it2;
        }
        return adj_num >= 2;
    }
};