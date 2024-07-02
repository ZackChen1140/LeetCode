class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        auto it1 = height.begin(), it2 = height.end() - 1;
        while(it2 > it1)
        {
            int new_water = min(*it1, *it2) * (it2 - it1);
            water = max(water, new_water);
            *it1 > *it2 ? --it2 : ++it1;
        }
        return water;
    }
};