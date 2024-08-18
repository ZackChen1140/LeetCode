class Solution {
private:
    vector<bool> homeRoad;
    vector<vector<pair<int, int>>> cities;
    int revN = 0;
    void gatherConn(int city)
    {
        for(int i = 0; i < cities[city].size(); ++i)
            if(!homeRoad[cities[city][i].first])
            {
                int tCity = cities[city][i].first;
                if(!cities[city][i].second)
                {
                    (*find(cities[tCity].begin(), cities[tCity].end(), make_pair(city, 1))).second = 0;
                    cities[city][i].second = 1, ++revN;
                }
                homeRoad[tCity] = true, gatherConn(tCity);
            }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections)
    {
        homeRoad.assign(n, false), homeRoad[0] = true, cities.assign(n, {});
        for(auto& c : connections)
            cities[c[0]].emplace_back(make_pair(c[1], 0)), cities[c[1]].emplace_back(make_pair(c[0], 1));
        for(int i = 0; i < cities.size(); ++i) if(homeRoad[i]) gatherConn(i);
        return revN;
    }
};