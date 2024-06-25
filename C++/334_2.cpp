class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int l = INT_MAX, m = INT_MAX;
        for(int n : nums)
        {
            if(n <= l) l = n;
            else if(n <= m) m = n;
            else return true;
        }
        return false;
    }
};