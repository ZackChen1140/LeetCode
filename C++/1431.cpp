class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> rArray(candies.size(), false);
        for(int i = 0; i < candies.size(); ++i) if(candies[i] >= *max_element(candies.begin(), candies.end()) - extraCandies) rArray[i] = true;
        return rArray;
    }
};