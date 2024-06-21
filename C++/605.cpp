class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.emplace(flowerbed.begin(), 0), flowerbed.emplace_back(0);
        for (int i = 1; i < flowerbed.size() - 1; ++i) if(flowerbed[i] + flowerbed[i - 1] + flowerbed[i + 1] == 0) flowerbed[i] = 1, --n;
        return n <= 0;
    }
};