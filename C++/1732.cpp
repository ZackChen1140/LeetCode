class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int high = 0;
        gain.emplace(gain.begin(), 0);
        for(int i = 1; i < gain.size(); ++i) high = max(high, gain[i] += gain[i - 1]);
        return high;
    }
};