class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ra;
        auto it = asteroids.begin();
        while(it != asteroids.end())
        {
            if(ra.empty() || *it > 0 || ra.back() < 0) ra.emplace_back(*it++);
            else if(ra.back() > abs(*it)) ++it;
            else if(ra.back() + *it == 0) ra.pop_back(), ++it;
            else while(!ra.empty() && ra.back() > 0 && abs(ra.back()) < abs(*it)) ra.pop_back();
        }
        return ra;
    }
};